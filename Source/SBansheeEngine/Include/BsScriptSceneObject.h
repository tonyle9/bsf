//********************************** Banshee Engine (www.banshee3d.com) **************************************************//
//**************** Copyright (c) 2016 Marko Pintera (marko.pintera@gmail.com). All rights reserved. **********************//
#pragma once

#include "BsScriptEnginePrerequisites.h"
#include "BsScriptGameObject.h"
#include "BsScriptObject.h"
#include "BsFont.h"

namespace bs
{
	/** @addtogroup ScriptInteropEngine
	 *  @{
	 */

	/**	Interop class between C++ & CLR for SceneObject. */
	class BS_SCR_BE_EXPORT ScriptSceneObject : public ScriptObject<ScriptSceneObject, ScriptGameObjectBase>
	{
	public:
		SCRIPT_OBJ(ENGINE_ASSEMBLY, "BansheeEngine", "SceneObject")

		/** @copydoc ScriptGameObjectBase::getNativeHandle */
		HGameObject getNativeHandle() const override { return mSceneObject; }

		/** @copydoc ScriptGameObjectBase::setNativeHandle */
		void setNativeHandle(const HGameObject& gameObject) override;

		/**	Returns the native internal scene object. */
		HSceneObject getNativeSceneObject() const { return mSceneObject; }

		/**	Checks is the scene object wrapped by the provided interop object destroyed. */
		static bool checkIfDestroyed(ScriptSceneObject* nativeInstance);

	private:
		friend class ScriptGameObjectManager;

		ScriptSceneObject(MonoObject* instance, const HSceneObject& sceneObject);

		/** @copydoc ScriptObjectBase::_onManagedInstanceDeleted */
		void _onManagedInstanceDeleted() override;

		/** @copydoc ScriptObjectBase::_createManagedInstance */
		MonoObject* _createManagedInstance(bool construct) override;

		/**	Triggered by the script game object manager when the handle this object is referencing is destroyed. */
		void _notifyDestroyed();

		HSceneObject mSceneObject;
		uint32_t mManagedHandle;

		/************************************************************************/
		/* 								CLR HOOKS						   		*/
		/************************************************************************/
		static void internal_createInstance(MonoObject* instance, MonoString* name, UINT32 flags);

		static void internal_setName(ScriptSceneObject* nativeInstance, MonoString* name);
		static MonoString* internal_getName(ScriptSceneObject* nativeInstance);
		static void internal_setActive(ScriptSceneObject* nativeInstance, bool value);
		static bool internal_getActive(ScriptSceneObject* nativeInstance);

		static void internal_setMobility(ScriptSceneObject* nativeInstance, int value);
		static int internal_getMobility(ScriptSceneObject* nativeInstance);

		static void internal_setParent(ScriptSceneObject* nativeInstance, MonoObject* parent);
		static MonoObject* internal_getParent(ScriptSceneObject* nativeInstance);

		static void internal_getNumChildren(ScriptSceneObject* nativeInstance, UINT32* value);
		static MonoObject* internal_getChild(ScriptSceneObject* nativeInstance, UINT32 idx);
		static MonoObject* internal_findChild(ScriptSceneObject* nativeInstance, MonoString* name, bool recursive);
		static MonoArray* internal_findChildren(ScriptSceneObject* nativeInstance, MonoString* name, bool recursive);

		static void internal_getPosition(ScriptSceneObject* nativeInstance, Vector3* value);
		static void internal_getLocalPosition(ScriptSceneObject* nativeInstance, Vector3* value);
		static void internal_getRotation(ScriptSceneObject* nativeInstance, Quaternion* value);
		static void internal_getLocalRotation(ScriptSceneObject* nativeInstance, Quaternion* value);
		static void internal_getScale(ScriptSceneObject* nativeInstance, Vector3* value);
		static void internal_getLocalScale(ScriptSceneObject* nativeInstance, Vector3* value);

		static void internal_setPosition(ScriptSceneObject* nativeInstance, Vector3* value);
		static void internal_setLocalPosition(ScriptSceneObject* nativeInstance, Vector3* value);
		static void internal_setRotation(ScriptSceneObject* nativeInstance, Quaternion* value);
		static void internal_setLocalRotation(ScriptSceneObject* nativeInstance, Quaternion* value);
		static void internal_setLocalScale(ScriptSceneObject* nativeInstance, Vector3* value);

		static void internal_getLocalTransform(ScriptSceneObject* nativeInstance, Matrix4* value);
		static void internal_getWorldTransform(ScriptSceneObject* nativeInstance, Matrix4* value);
		static void internal_lookAt(ScriptSceneObject* nativeInstance, Vector3* direction, Vector3* up);
		static void internal_move(ScriptSceneObject* nativeInstance, Vector3* value);
		static void internal_moveLocal(ScriptSceneObject* nativeInstance, Vector3* value);
		static void internal_rotate(ScriptSceneObject* nativeInstance, Quaternion* value);
		static void internal_roll(ScriptSceneObject* nativeInstance, Radian* value);
		static void internal_yaw(ScriptSceneObject* nativeInstance, Radian* value);
		static void internal_pitch(ScriptSceneObject* nativeInstance, Radian* value);
		static void internal_setForward(ScriptSceneObject* nativeInstance, Vector3* value);
		static void internal_getForward(ScriptSceneObject* nativeInstance, Vector3* value);
		static void internal_getUp(ScriptSceneObject* nativeInstance, Vector3* value);
		static void internal_getRight(ScriptSceneObject* nativeInstance, Vector3* value);

		static void internal_destroy(ScriptSceneObject* nativeInstance, bool immediate);
	};

	/** @} */
}