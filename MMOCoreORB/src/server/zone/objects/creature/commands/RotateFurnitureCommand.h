/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/

#ifndef ROTATEFURNITURECOMMAND_H_
#define ROTATEFURNITURECOMMAND_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/tangible/components/vendor/VendorDataComponent.h"
#include "server/zone/objects/tangible/components/EventPerkDataComponent.h"
#include "server/zone/managers/player/PlayerManager.h"

class RotateFurnitureCommand : public QueueCommand {
public:

	RotateFurnitureCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

		if (ghost == NULL)
			return GENERALERROR;

		String dir;
		int degrees = 0;
		
		// Alternate Rotation Style: Yaw, Pitch, Roll and Reset the rotation. Does not have radial menu options.
		// Note: The SWG 14.1 style rotation can still be used, with the commands and radial menu.
		try {
			UnicodeTokenizer tokenizer(arguments.toString());
			tokenizer.getStringToken(dir);
			degrees = tokenizer.getIntToken();

			dir = dir.toLowerCase();

			if  (dir != "left" && dir != "right" && dir != "yaw" && dir != "roll" && dir != "pitch" && dir != "reset" && dir != "yxx" && dir != "pxx" && dir != "rxx" && dir != "xresetx")
				throw Exception();

		} catch (Exception& e) {
			creature->sendSystemMessage("Standard Format: /rotateFurniture <LEFT/RIGHT> <degrees>. Degrees can be 1 to 180 when using this format."); 
			creature->sendSystemMessage("Enhanced Format: /rotateFurniture <YAW/PITCH/ROLL> <degrees>. Degrees can be -360 to 360 when using this format.");
			creature->sendSystemMessage("Reset Rotation to Defaults: /rotateFurniture reset 1"); 		
			// Work-around for the targetting string issues
			creature->sendSystemMessage("If using yaw, pitch, roll, or reset properly gives you this message, try using Yxx Pxx Rxx XresetX instead. The problem is caused by a nearby item's name starting with yaw, pitch, roll, or reset.");		
			return INVALIDPARAMETERS;
		}

		if ((dir == "left" || dir == "right") && (degrees < 1 || degrees > 180)) {
			creature->sendSystemMessage("Using Standard Format: The amount to rotate must be between 1 and 180."); 
			return INVALIDPARAMETERS;
		}
		
		if ((dir == "roll" || dir == "pitch" || dir == "yaw" ) && (degrees < -360 || degrees > 360)) {
			creature->sendSystemMessage("Using Enhanced Format: The amount to rotate must be between -360 and 360."); 
			return INVALIDPARAMETERS;
		}

		ZoneServer* zoneServer = creature->getZoneServer();
		ManagedReference<SceneObject*> obj = zoneServer->getObject(target);

		if (obj == NULL || !obj->isTangibleObject() || obj->isPlayerCreature() || obj->isPet()) {
			creature->sendSystemMessage("@player_structure:rotate_what"); //What do you want to rotate?
			return GENERALERROR;
		}

		ManagedReference<SceneObject*> rootParent = creature->getRootParent();

		BuildingObject* buildingObject = rootParent != NULL ? (rootParent->isBuildingObject() ? cast<BuildingObject*>( rootParent.get()) : NULL) : NULL;
		EventPerkDataComponent* data = cast<EventPerkDataComponent*>(obj->getDataObjectComponent()->get());

		if (data != NULL) {
			EventPerkDeed* deed = data->getDeed();

			if (deed == NULL) {
				return GENERALERROR;
			}

			ManagedReference<CreatureObject*> owner = deed->getOwner().get();

			if (owner != creature) {
				return GENERALERROR;
			}

		} else if (buildingObject == NULL) {
			creature->sendSystemMessage("@player_structure:must_be_in_building"); //You must be in a building to do that.
			return GENERALERROR;

		} else {
			if (obj->isVendor() && !obj->checkContainerPermission(creature, ContainerPermissions::MOVEVENDOR)) {
				return GENERALERROR;
			}

			if (!obj->isVendor() && !buildingObject->isOnAdminList(creature)) {
				creature->sendSystemMessage("@player_structure:must_be_admin"); //You must be a building admin to do that.
				return GENERALERROR;
			}

			if (obj->getRootParent() != buildingObject || buildingObject->containsChildObject(obj)) {
				creature->sendSystemMessage("@player_structure:rotate_what"); //What do you want to rotate?
				return GENERALERROR;
			}

			if (buildingObject->isGCWBase()) {
				creature->sendSystemMessage("@player_structure:no_move_hq"); // You may not move or rotate objects inside a factional headquarters.
				return GENERALERROR;
			}
		}

		if (dir == "right"){
			obj->rotate(-degrees);
		}
		else if (dir == "left"){
			obj->rotate(degrees);
		}
		else if (dir == "yaw" || dir == "yxx"){
			obj->rotate(degrees);
		}
		else if (dir == "pitch" || dir == "pxx"){
			obj->rotateYaxis(degrees);
		}
		else if (dir == "roll" || dir == "rxx"){
			obj->rotateXaxis(degrees);
		}
		else if (dir == "reset" || dir == "xresetx"){
			obj->setDirection(1, 0, 0, 0);
		}
		
		obj->incrementMovementCounter();

		if (obj->getParent() != NULL)
			obj->teleport(obj->getPositionX(), obj->getPositionZ(), obj->getPositionY(), obj->getParent().get()->getObjectID());
		else
			obj->teleport(obj->getPositionX(), obj->getPositionZ(), obj->getPositionY());

		return SUCCESS;
	}

};

#endif //ROTATEFURNITURECOMMAND_H_
