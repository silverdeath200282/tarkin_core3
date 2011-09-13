/*
 *	server/zone/objects/draftschematic/DraftSchematic.cpp generated by engine3 IDL compiler 0.60
 */

#include "DraftSchematic.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/templates/SharedObjectTemplate.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/area/ActiveArea.h"

/*
 *	DraftSchematicStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__ = 6,RPC_SENDBASELINESTO__SCENEOBJECT_,RPC_SENDDRAFTSLOTSTO__CREATUREOBJECT_,RPC_SENDRESOURCEWEIGHTSTO__CREATUREOBJECT_,RPC_CREATEMANUFACTURESCHEMATIC__SCENEOBJECT_,RPC_SETSCHEMATICID__INT_,RPC_GETSCHEMATICID__,RPC_SETGROUPNAME__STRING_,RPC_GETGROUPNAME__,RPC_GETDRAFTSLOTCOUNT__,RPC_ISVALIDDRAFTSCHEMATIC__,RPC_GETRESOURCEWEIGHTCOUNT__,RPC_GETCOMPLEXITY__,RPC_GETTOOLTAB__,RPC_GETSIZE__,RPC_GETXPTYPE__,RPC_GETXPAMOUNT__,RPC_GETASSEMBLYSKILL__,RPC_GETEXPERIMENTATIONSKILL__,RPC_GETCUSTOMIZATIONSKILL__,RPC_GETCUSTOMNAME__,RPC_GETTANOCRC__,RPC_GETUSECOUNT__,RPC_SETUSECOUNT__INT_,RPC_DECREASEUSECOUNT__INT_,RPC_INCREASEUSECOUNT__INT_,RPC_GETTEMPLATELISTSIZE__,RPC_GETTEMPLATE__INT_};

DraftSchematic::DraftSchematic() : IntangibleObject(DummyConstructorParameter::instance()) {
	DraftSchematicImplementation* _implementation = new DraftSchematicImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

DraftSchematic::DraftSchematic(DummyConstructorParameter* param) : IntangibleObject(param) {
}

DraftSchematic::~DraftSchematic() {
}


void DraftSchematic::initializeTransientMembers() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void DraftSchematic::loadTemplateData(SharedObjectTemplate* templateData) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

void DraftSchematic::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

void DraftSchematic::sendBaselinesTo(SceneObject* player) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDBASELINESTO__SCENEOBJECT_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendBaselinesTo(player);
}

void DraftSchematic::sendDraftSlotsTo(CreatureObject* player) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDDRAFTSLOTSTO__CREATUREOBJECT_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendDraftSlotsTo(player);
}

void DraftSchematic::sendResourceWeightsTo(CreatureObject* player) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDRESOURCEWEIGHTSTO__CREATUREOBJECT_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendResourceWeightsTo(player);
}

SceneObject* DraftSchematic::createManufactureSchematic(SceneObject* craftingTool) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CREATEMANUFACTURESCHEMATIC__SCENEOBJECT_);
		method.addObjectParameter(craftingTool);

		return (SceneObject*) method.executeWithObjectReturn();
	} else
		return _implementation->createManufactureSchematic(craftingTool);
}

void DraftSchematic::setSchematicID(unsigned int id) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETSCHEMATICID__INT_);
		method.addUnsignedIntParameter(id);

		method.executeWithVoidReturn();
	} else
		_implementation->setSchematicID(id);
}

unsigned int DraftSchematic::getSchematicID() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSCHEMATICID__);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getSchematicID();
}

void DraftSchematic::setGroupName(String& name) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETGROUPNAME__STRING_);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		_implementation->setGroupName(name);
}

String DraftSchematic::getGroupName() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETGROUPNAME__);

		method.executeWithAsciiReturn(_return_getGroupName);
		return _return_getGroupName;
	} else
		return _implementation->getGroupName();
}

int DraftSchematic::getDraftSlotCount() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETDRAFTSLOTCOUNT__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getDraftSlotCount();
}

bool DraftSchematic::isValidDraftSchematic() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISVALIDDRAFTSCHEMATIC__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isValidDraftSchematic();
}

DraftSlot* DraftSchematic::getDraftSlot(int i) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getDraftSlot(i);
}

int DraftSchematic::getResourceWeightCount() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETRESOURCEWEIGHTCOUNT__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getResourceWeightCount();
}

ResourceWeight* DraftSchematic::getResourceWeight(int i) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getResourceWeight(i);
}

float DraftSchematic::getComplexity() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCOMPLEXITY__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getComplexity();
}

unsigned int DraftSchematic::getToolTab() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETTOOLTAB__);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getToolTab();
}

float DraftSchematic::getSize() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETSIZE__);

		return method.executeWithFloatReturn();
	} else
		return _implementation->getSize();
}

String DraftSchematic::getXpType() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETXPTYPE__);

		method.executeWithAsciiReturn(_return_getXpType);
		return _return_getXpType;
	} else
		return _implementation->getXpType();
}

int DraftSchematic::getXpAmount() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETXPAMOUNT__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getXpAmount();
}

String DraftSchematic::getAssemblySkill() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETASSEMBLYSKILL__);

		method.executeWithAsciiReturn(_return_getAssemblySkill);
		return _return_getAssemblySkill;
	} else
		return _implementation->getAssemblySkill();
}

String DraftSchematic::getExperimentationSkill() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETEXPERIMENTATIONSKILL__);

		method.executeWithAsciiReturn(_return_getExperimentationSkill);
		return _return_getExperimentationSkill;
	} else
		return _implementation->getExperimentationSkill();
}

String DraftSchematic::getCustomizationSkill() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCUSTOMIZATIONSKILL__);

		method.executeWithAsciiReturn(_return_getCustomizationSkill);
		return _return_getCustomizationSkill;
	} else
		return _implementation->getCustomizationSkill();
}

Vector<byte>* DraftSchematic::getCustomizationOptions() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getCustomizationOptions();
}

Vector<String>* DraftSchematic::getCustomizationStringNames() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getCustomizationStringNames();
}

Vector<byte>* DraftSchematic::getCustomizationDefaultValues() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		return _implementation->getCustomizationDefaultValues();
}

String DraftSchematic::getCustomName() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCUSTOMNAME__);

		method.executeWithAsciiReturn(_return_getCustomName);
		return _return_getCustomName;
	} else
		return _implementation->getCustomName();
}

unsigned int DraftSchematic::getTanoCRC() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETTANOCRC__);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getTanoCRC();
}

int DraftSchematic::getUseCount() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETUSECOUNT__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getUseCount();
}

void DraftSchematic::setUseCount(int count) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETUSECOUNT__INT_);
		method.addSignedIntParameter(count);

		method.executeWithVoidReturn();
	} else
		_implementation->setUseCount(count);
}

void DraftSchematic::decreaseUseCount(int count) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_DECREASEUSECOUNT__INT_);
		method.addSignedIntParameter(count);

		method.executeWithVoidReturn();
	} else
		_implementation->decreaseUseCount(count);
}

void DraftSchematic::increaseUseCount(int count) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INCREASEUSECOUNT__INT_);
		method.addSignedIntParameter(count);

		method.executeWithVoidReturn();
	} else
		_implementation->increaseUseCount(count);
}

int DraftSchematic::getTemplateListSize() {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETTEMPLATELISTSIZE__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getTemplateListSize();
}

String DraftSchematic::getTemplate(int i) {
	DraftSchematicImplementation* _implementation = (DraftSchematicImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETTEMPLATE__INT_);
		method.addSignedIntParameter(i);

		method.executeWithAsciiReturn(_return_getTemplate);
		return _return_getTemplate;
	} else
		return _implementation->getTemplate(i);
}

DistributedObjectServant* DraftSchematic::_getImplementation() {

	_updated = true;
	return _impl;
}

void DraftSchematic::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	DraftSchematicImplementation
 */

DraftSchematicImplementation::DraftSchematicImplementation(DummyConstructorParameter* param) : IntangibleObjectImplementation(param) {
	_initializeImplementation();
}


DraftSchematicImplementation::~DraftSchematicImplementation() {
}


void DraftSchematicImplementation::finalize() {
}

void DraftSchematicImplementation::_initializeImplementation() {
	_setClassHelper(DraftSchematicHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void DraftSchematicImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (DraftSchematic*) stub;
	IntangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* DraftSchematicImplementation::_getStub() {
	return _this;
}

DraftSchematicImplementation::operator const DraftSchematic*() {
	return _this;
}

void DraftSchematicImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void DraftSchematicImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void DraftSchematicImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void DraftSchematicImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void DraftSchematicImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void DraftSchematicImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void DraftSchematicImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void DraftSchematicImplementation::_serializationHelperMethod() {
	IntangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("DraftSchematic");

}

void DraftSchematicImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(DraftSchematicImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool DraftSchematicImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (IntangibleObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "schematicID") {
		TypeInfo<unsigned int >::parseFromBinaryStream(&schematicID, stream);
		return true;
	}

	if (_name == "useCount") {
		TypeInfo<int >::parseFromBinaryStream(&useCount, stream);
		return true;
	}


	return false;
}

void DraftSchematicImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = DraftSchematicImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int DraftSchematicImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "schematicID";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<unsigned int >::toBinaryStream(&schematicID, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);

	_name = "useCount";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<int >::toBinaryStream(&useCount, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 2 + IntangibleObjectImplementation::writeObjectMembers(stream);
}

DraftSchematicImplementation::DraftSchematicImplementation() {
	_initializeImplementation();
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		schematicTemplate = null;
	schematicTemplate = NULL;
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		useCount = 0;
	useCount = 0;
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		schematicID = 0;
	schematicID = 0;
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		groupName = "";
	groupName = "";
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		Logger.setLoggingName("DraftSchematic");
	Logger::setLoggingName("DraftSchematic");
}

void DraftSchematicImplementation::setSchematicID(unsigned int id) {
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		schematicID = id;
	schematicID = id;
}

unsigned int DraftSchematicImplementation::getSchematicID() {
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		return schematicID;
	return schematicID;
}

void DraftSchematicImplementation::setGroupName(String& name) {
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		groupName = name;
	groupName = name;
}

String DraftSchematicImplementation::getGroupName() {
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		return groupName;
	return groupName;
}

bool DraftSchematicImplementation::isValidDraftSchematic() {
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		return schematicTemplate != null;
	return schematicTemplate != NULL;
}

int DraftSchematicImplementation::getUseCount() {
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		return useCount;
	return useCount;
}

void DraftSchematicImplementation::setUseCount(int count) {
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		useCount = count;
	useCount = count;
}

void DraftSchematicImplementation::decreaseUseCount(int count) {
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		setUseCount(useCount - 1);
	setUseCount(useCount - 1);
}

void DraftSchematicImplementation::increaseUseCount(int count) {
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		setUseCount(useCount + count);
	setUseCount(useCount + count);
}

int DraftSchematicImplementation::getTemplateListSize() {
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		return schematicTemplate.getTemplateListSize();
	return schematicTemplate->getTemplateListSize();
}

String DraftSchematicImplementation::getTemplate(int i) {
	// server/zone/objects/draftschematic/DraftSchematic.idl():  		return schematicTemplate.getTemplate(i);
	return schematicTemplate->getTemplate(i);
}

/*
 *	DraftSchematicAdapter
 */

DraftSchematicAdapter::DraftSchematicAdapter(DraftSchematicImplementation* obj) : IntangibleObjectAdapter(obj) {
}

Packet* DraftSchematicAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_SENDBASELINESTO__SCENEOBJECT_:
		sendBaselinesTo((SceneObject*) inv->getObjectParameter());
		break;
	case RPC_SENDDRAFTSLOTSTO__CREATUREOBJECT_:
		sendDraftSlotsTo((CreatureObject*) inv->getObjectParameter());
		break;
	case RPC_SENDRESOURCEWEIGHTSTO__CREATUREOBJECT_:
		sendResourceWeightsTo((CreatureObject*) inv->getObjectParameter());
		break;
	case RPC_CREATEMANUFACTURESCHEMATIC__SCENEOBJECT_:
		resp->insertLong(createManufactureSchematic((SceneObject*) inv->getObjectParameter())->_getObjectID());
		break;
	case RPC_SETSCHEMATICID__INT_:
		setSchematicID(inv->getUnsignedIntParameter());
		break;
	case RPC_GETSCHEMATICID__:
		resp->insertInt(getSchematicID());
		break;
	case RPC_SETGROUPNAME__STRING_:
		setGroupName(inv->getAsciiParameter(_param0_setGroupName__String_));
		break;
	case RPC_GETGROUPNAME__:
		resp->insertAscii(getGroupName());
		break;
	case RPC_GETDRAFTSLOTCOUNT__:
		resp->insertSignedInt(getDraftSlotCount());
		break;
	case RPC_ISVALIDDRAFTSCHEMATIC__:
		resp->insertBoolean(isValidDraftSchematic());
		break;
	case RPC_GETRESOURCEWEIGHTCOUNT__:
		resp->insertSignedInt(getResourceWeightCount());
		break;
	case RPC_GETCOMPLEXITY__:
		resp->insertFloat(getComplexity());
		break;
	case RPC_GETTOOLTAB__:
		resp->insertInt(getToolTab());
		break;
	case RPC_GETSIZE__:
		resp->insertFloat(getSize());
		break;
	case RPC_GETXPTYPE__:
		resp->insertAscii(getXpType());
		break;
	case RPC_GETXPAMOUNT__:
		resp->insertSignedInt(getXpAmount());
		break;
	case RPC_GETASSEMBLYSKILL__:
		resp->insertAscii(getAssemblySkill());
		break;
	case RPC_GETEXPERIMENTATIONSKILL__:
		resp->insertAscii(getExperimentationSkill());
		break;
	case RPC_GETCUSTOMIZATIONSKILL__:
		resp->insertAscii(getCustomizationSkill());
		break;
	case RPC_GETCUSTOMNAME__:
		resp->insertAscii(getCustomName());
		break;
	case RPC_GETTANOCRC__:
		resp->insertInt(getTanoCRC());
		break;
	case RPC_GETUSECOUNT__:
		resp->insertSignedInt(getUseCount());
		break;
	case RPC_SETUSECOUNT__INT_:
		setUseCount(inv->getSignedIntParameter());
		break;
	case RPC_DECREASEUSECOUNT__INT_:
		decreaseUseCount(inv->getSignedIntParameter());
		break;
	case RPC_INCREASEUSECOUNT__INT_:
		increaseUseCount(inv->getSignedIntParameter());
		break;
	case RPC_GETTEMPLATELISTSIZE__:
		resp->insertSignedInt(getTemplateListSize());
		break;
	case RPC_GETTEMPLATE__INT_:
		resp->insertAscii(getTemplate(inv->getSignedIntParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

void DraftSchematicAdapter::initializeTransientMembers() {
	((DraftSchematicImplementation*) impl)->initializeTransientMembers();
}

void DraftSchematicAdapter::sendBaselinesTo(SceneObject* player) {
	((DraftSchematicImplementation*) impl)->sendBaselinesTo(player);
}

void DraftSchematicAdapter::sendDraftSlotsTo(CreatureObject* player) {
	((DraftSchematicImplementation*) impl)->sendDraftSlotsTo(player);
}

void DraftSchematicAdapter::sendResourceWeightsTo(CreatureObject* player) {
	((DraftSchematicImplementation*) impl)->sendResourceWeightsTo(player);
}

SceneObject* DraftSchematicAdapter::createManufactureSchematic(SceneObject* craftingTool) {
	return ((DraftSchematicImplementation*) impl)->createManufactureSchematic(craftingTool);
}

void DraftSchematicAdapter::setSchematicID(unsigned int id) {
	((DraftSchematicImplementation*) impl)->setSchematicID(id);
}

unsigned int DraftSchematicAdapter::getSchematicID() {
	return ((DraftSchematicImplementation*) impl)->getSchematicID();
}

void DraftSchematicAdapter::setGroupName(String& name) {
	((DraftSchematicImplementation*) impl)->setGroupName(name);
}

String DraftSchematicAdapter::getGroupName() {
	return ((DraftSchematicImplementation*) impl)->getGroupName();
}

int DraftSchematicAdapter::getDraftSlotCount() {
	return ((DraftSchematicImplementation*) impl)->getDraftSlotCount();
}

bool DraftSchematicAdapter::isValidDraftSchematic() {
	return ((DraftSchematicImplementation*) impl)->isValidDraftSchematic();
}

int DraftSchematicAdapter::getResourceWeightCount() {
	return ((DraftSchematicImplementation*) impl)->getResourceWeightCount();
}

float DraftSchematicAdapter::getComplexity() {
	return ((DraftSchematicImplementation*) impl)->getComplexity();
}

unsigned int DraftSchematicAdapter::getToolTab() {
	return ((DraftSchematicImplementation*) impl)->getToolTab();
}

float DraftSchematicAdapter::getSize() {
	return ((DraftSchematicImplementation*) impl)->getSize();
}

String DraftSchematicAdapter::getXpType() {
	return ((DraftSchematicImplementation*) impl)->getXpType();
}

int DraftSchematicAdapter::getXpAmount() {
	return ((DraftSchematicImplementation*) impl)->getXpAmount();
}

String DraftSchematicAdapter::getAssemblySkill() {
	return ((DraftSchematicImplementation*) impl)->getAssemblySkill();
}

String DraftSchematicAdapter::getExperimentationSkill() {
	return ((DraftSchematicImplementation*) impl)->getExperimentationSkill();
}

String DraftSchematicAdapter::getCustomizationSkill() {
	return ((DraftSchematicImplementation*) impl)->getCustomizationSkill();
}

String DraftSchematicAdapter::getCustomName() {
	return ((DraftSchematicImplementation*) impl)->getCustomName();
}

unsigned int DraftSchematicAdapter::getTanoCRC() {
	return ((DraftSchematicImplementation*) impl)->getTanoCRC();
}

int DraftSchematicAdapter::getUseCount() {
	return ((DraftSchematicImplementation*) impl)->getUseCount();
}

void DraftSchematicAdapter::setUseCount(int count) {
	((DraftSchematicImplementation*) impl)->setUseCount(count);
}

void DraftSchematicAdapter::decreaseUseCount(int count) {
	((DraftSchematicImplementation*) impl)->decreaseUseCount(count);
}

void DraftSchematicAdapter::increaseUseCount(int count) {
	((DraftSchematicImplementation*) impl)->increaseUseCount(count);
}

int DraftSchematicAdapter::getTemplateListSize() {
	return ((DraftSchematicImplementation*) impl)->getTemplateListSize();
}

String DraftSchematicAdapter::getTemplate(int i) {
	return ((DraftSchematicImplementation*) impl)->getTemplate(i);
}

/*
 *	DraftSchematicHelper
 */

DraftSchematicHelper* DraftSchematicHelper::staticInitializer = DraftSchematicHelper::instance();

DraftSchematicHelper::DraftSchematicHelper() {
	className = "DraftSchematic";

	Core::getObjectBroker()->registerClass(className, this);
}

void DraftSchematicHelper::finalizeHelper() {
	DraftSchematicHelper::finalize();
}

DistributedObject* DraftSchematicHelper::instantiateObject() {
	return new DraftSchematic(DummyConstructorParameter::instance());
}

DistributedObjectServant* DraftSchematicHelper::instantiateServant() {
	return new DraftSchematicImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* DraftSchematicHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new DraftSchematicAdapter((DraftSchematicImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

