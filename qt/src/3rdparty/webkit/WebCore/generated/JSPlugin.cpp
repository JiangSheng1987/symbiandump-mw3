/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSPlugin.h"

#include "AtomicString.h"
#include "JSMimeType.h"
#include "KURL.h"
#include "MimeType.h"
#include "Plugin.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <runtime/JSString.h>
#include <runtime/PropertyNameArray.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSPlugin);

/* Hash table */

static const HashTableValue JSPluginTableValues[6] =
{
    { "name", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsPluginName), (intptr_t)0 },
    { "filename", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsPluginFilename), (intptr_t)0 },
    { "description", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsPluginDescription), (intptr_t)0 },
    { "length", DontDelete|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsPluginLength), (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)static_cast<PropertySlot::GetValueFunc>(jsPluginConstructor), (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSPluginTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 127, JSPluginTableValues, 0 };
#else
    { 17, 15, JSPluginTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSPluginConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSPluginConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSPluginConstructorTableValues, 0 };
#else
    { 1, 0, JSPluginConstructorTableValues, 0 };
#endif

class JSPluginConstructor : public DOMConstructorObject {
public:
    JSPluginConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSPluginConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSPluginPrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags), AnonymousSlotCount); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSPluginConstructor::s_info = { "PluginConstructor", 0, &JSPluginConstructorTable, 0 };

bool JSPluginConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSPluginConstructor, DOMObject>(exec, &JSPluginConstructorTable, this, propertyName, slot);
}

bool JSPluginConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSPluginConstructor, DOMObject>(exec, &JSPluginConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSPluginPrototypeTableValues[3] =
{
    { "item", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsPluginPrototypeFunctionItem), (intptr_t)1 },
    { "namedItem", DontDelete|Function, (intptr_t)static_cast<NativeFunction>(jsPluginPrototypeFunctionNamedItem), (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSPluginPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 7, JSPluginPrototypeTableValues, 0 };
#else
    { 5, 3, JSPluginPrototypeTableValues, 0 };
#endif

const ClassInfo JSPluginPrototype::s_info = { "PluginPrototype", 0, &JSPluginPrototypeTable, 0 };

JSObject* JSPluginPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSPlugin>(exec, globalObject);
}

bool JSPluginPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSPluginPrototypeTable, this, propertyName, slot);
}

bool JSPluginPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSPluginPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSPlugin::s_info = { "Plugin", 0, &JSPluginTable, 0 };

JSPlugin::JSPlugin(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<Plugin> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSPlugin::~JSPlugin()
{
    forgetDOMObject(this, impl());
}

JSObject* JSPlugin::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSPluginPrototype(JSPluginPrototype::createStructure(globalObject->objectPrototype()));
}

bool JSPlugin::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    const HashEntry* entry = JSPluginTable.entry(exec, propertyName);
    if (entry) {
        slot.setCustom(this, entry->propertyGetter());
        return true;
    }
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok && index < static_cast<Plugin*>(impl())->length()) {
        slot.setCustomIndex(this, index, indexGetter);
        return true;
    }
    if (canGetItemsForName(exec, static_cast<Plugin*>(impl()), propertyName)) {
        slot.setCustom(this, nameGetter);
        return true;
    }
    return getStaticValueSlot<JSPlugin, Base>(exec, &JSPluginTable, this, propertyName, slot);
}

bool JSPlugin::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    const HashEntry* entry = JSPluginTable.entry(exec, propertyName);
    if (entry) {
        PropertySlot slot;
        slot.setCustom(this, entry->propertyGetter());
        descriptor.setDescriptor(slot.getValue(exec, propertyName), entry->attributes());
        return true;
    }
    bool ok;
    unsigned index = propertyName.toUInt32(&ok, false);
    if (ok && index < static_cast<Plugin*>(impl())->length()) {
        PropertySlot slot;
        slot.setCustomIndex(this, index, indexGetter);
        descriptor.setDescriptor(slot.getValue(exec, propertyName), DontDelete | ReadOnly);
        return true;
    }
    if (canGetItemsForName(exec, static_cast<Plugin*>(impl()), propertyName)) {
        PropertySlot slot;
        slot.setCustom(this, nameGetter);
        descriptor.setDescriptor(slot.getValue(exec, propertyName), ReadOnly | DontDelete | DontEnum);
        return true;
    }
    return getStaticValueDescriptor<JSPlugin, Base>(exec, &JSPluginTable, this, propertyName, descriptor);
}

bool JSPlugin::getOwnPropertySlot(ExecState* exec, unsigned propertyName, PropertySlot& slot)
{
    if (propertyName < static_cast<Plugin*>(impl())->length()) {
        slot.setCustomIndex(this, propertyName, indexGetter);
        return true;
    }
    return getOwnPropertySlot(exec, Identifier::from(exec, propertyName), slot);
}

JSValue jsPluginName(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSPlugin* castedThis = static_cast<JSPlugin*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Plugin* imp = static_cast<Plugin*>(castedThis->impl());
    JSValue result = jsString(exec, imp->name());
    return result;
}

JSValue jsPluginFilename(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSPlugin* castedThis = static_cast<JSPlugin*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Plugin* imp = static_cast<Plugin*>(castedThis->impl());
    JSValue result = jsString(exec, imp->filename());
    return result;
}

JSValue jsPluginDescription(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSPlugin* castedThis = static_cast<JSPlugin*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Plugin* imp = static_cast<Plugin*>(castedThis->impl());
    JSValue result = jsString(exec, imp->description());
    return result;
}

JSValue jsPluginLength(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSPlugin* castedThis = static_cast<JSPlugin*>(asObject(slotBase));
    UNUSED_PARAM(exec);
    Plugin* imp = static_cast<Plugin*>(castedThis->impl());
    JSValue result = jsNumber(exec, imp->length());
    return result;
}

JSValue jsPluginConstructor(ExecState* exec, JSValue slotBase, const Identifier&)
{
    JSPlugin* domObject = static_cast<JSPlugin*>(asObject(slotBase));
    return JSPlugin::getConstructor(exec, domObject->globalObject());
}
void JSPlugin::getOwnPropertyNames(ExecState* exec, PropertyNameArray& propertyNames, EnumerationMode mode)
{
    for (unsigned i = 0; i < static_cast<Plugin*>(impl())->length(); ++i)
        propertyNames.add(Identifier::from(exec, i));
     Base::getOwnPropertyNames(exec, propertyNames, mode);
}

JSValue JSPlugin::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSPluginConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsPluginPrototypeFunctionItem(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSPlugin::s_info))
        return throwError(exec, TypeError);
    JSPlugin* castedThisObj = static_cast<JSPlugin*>(asObject(thisValue));
    Plugin* imp = static_cast<Plugin*>(castedThisObj->impl());
    unsigned index = args.at(0).toInt32(exec);


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->item(index)));
    return result;
}

JSValue JSC_HOST_CALL jsPluginPrototypeFunctionNamedItem(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSPlugin::s_info))
        return throwError(exec, TypeError);
    JSPlugin* castedThisObj = static_cast<JSPlugin*>(asObject(thisValue));
    Plugin* imp = static_cast<Plugin*>(castedThisObj->impl());
    const UString& name = args.at(0).toString(exec);


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->namedItem(name)));
    return result;
}


JSValue JSPlugin::indexGetter(ExecState* exec, JSValue slotBase, unsigned index)
{
    JSPlugin* thisObj = static_cast<JSPlugin*>(asObject(slotBase));
    return toJS(exec, thisObj->globalObject(), static_cast<Plugin*>(thisObj->impl())->item(index));
}
JSC::JSValue toJS(JSC::ExecState* exec, JSDOMGlobalObject* globalObject, Plugin* object)
{
    return getDOMObjectWrapper<JSPlugin>(exec, globalObject, object);
}
Plugin* toPlugin(JSC::JSValue value)
{
    return value.inherits(&JSPlugin::s_info) ? static_cast<JSPlugin*>(asObject(value))->impl() : 0;
}

}