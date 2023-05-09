#pragma once

namespace StringConverter 
{
	inline std::wstring ToUnicode(const std::string& str) {
		using convert_typeX = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_typeX, wchar_t> converterX;

		return converterX.from_bytes(str);
	}

	inline std::string ToASCII(const std::wstring& wstr) {
		using convert_typeX = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_typeX, wchar_t> converterX;

		return converterX.to_bytes(wstr);
	}
}

class ListDictionary 
{
public:
	char pad_0000[0x20];
	class BufferList* keys;
	class BufferList* vals;
};

class BufferList 
{
public:
	char pad_0000[0x10];
	int32_t size;
	char pad_0014[0x4];
	void* buffer;
};

template<typename T = void*>
class Array 
{
public:
	uint32_t ArraySize() {
		return *reinterpret_cast<uint32_t*>(this + 0x18);
	}
	T GetArray(int idx) {
		return *reinterpret_cast<T*>(this + (0x20 + (idx * 0x8)));
	}
	void AddArray(int idx, T value) {
		*reinterpret_cast<T*>(this + (0x20 + (idx * 0x8))) = value;
	}
};

class String 
{
public:
	char pad_0000[0x10];
	int len;
	wchar_t buffer[0];

	static String* Il2CPPNewString(const char* str) 
	{
		return reinterpret_cast<String * (__fastcall*)(const char*)>(GetProcAddress(GetModuleHandleA("GameAssembly.dll"), "il2cpp_string_new"))(str);
	}
};

enum LayerMask 
{
	Default = 1,
	TransparentFX = 2,
	Ignore_Raycast = 4,
	Reserved1 = 8,
	Water = 16,
	UI = 32,
	Reserved2 = 64,
	Reserved3 = 128,
	Deployed = 256,
	Ragdoll = 512,
	Invisible = 1024,
	AI = 2048,
	Player_Movement = 4096,
	Vehicle_Detailed = 8192,
	Game_Trace = 16384,
	Vehicle_World = 32768,
	World = 65536,
	Player_Server = 131072,
	Trigger = 262144,
	Player_Model_Rendering = 524288,
	Physics_Projectile = 1048576,
	Construction = 2097152,
	Construction_Socket = 4194304,
	Terrain = 8388608,
	Transparent = 16777216,
	Clutter = 33554432,
	Debris = 67108864,
	Vehicle_Large = 134217728,
	Prevent_Movement = 268435456,
	Prevent_Building = 536870912,
	Tree = 1073741824,
	Unused2 = -2147483648,
};

struct Ray
{
public:
	Vector3D origin;
	Vector3D direction;

	Ray()
	{
		this->origin.Clear();
		this->direction.Clear();
	}

	Ray(Vector3D origin, Vector3D direction)
	{
		this->origin = origin;
		this->direction = direction;
	}
};

namespace UnityEngine 
{
	enum TextAnchor {
		UpperLeft = 0,
		UpperCenter = 1,
		UpperRight = 2,
		MiddleLeft = 3,
		MiddleCenter = 4,
		MiddleRight = 5,
		LowerLeft = 6,
		LowerCenter = 7,
		LowerRight = 8,
	};

	class Time {
	public:
		CLASS("UnityEngine", "Time");

		static float GetTime()
		{
			METHOD(float(**)(), get_time);
			return get_time();
		}

		static float GetDeltaTime()
		{
			METHOD(float(**)(), get_deltaTime);
			return get_deltaTime();
		}

		static float GetUnscaledTime()
		{
			METHOD(float(**)(), get_unscaledTime);
			return get_unscaledTime();
		}

		static float GetFixedTime() 
		{
			METHOD(float(**)(), get_fixedTime);
			return get_fixedTime();
		}

		static float GetFixedDeltaTime() 
		{
			METHOD(float(**)(), get_fixedDeltaTime);
			return get_fixedDeltaTime();
		}

		static float GetMaximumDeltaTime()
		{
			METHOD(float(**)(), get_maximumDeltaTime);
			return get_maximumDeltaTime();
		}

		static float GetSmoothDeltaTime() 
		{
			METHOD(float(**)(), get_smoothDeltaTime);
			return get_smoothDeltaTime();
		}

		static float GetTimeScale() 
		{
			METHOD(float(**)(), get_timeScale);
			return get_timeScale();
		}

		static float GetRealtimeSinceStartup() 
		{
			METHOD(float(**)(), get_realtimeSinceStartup);
			return get_realtimeSinceStartup();
		}
	};

	class Screen 
	{
	public:
		CLASS("UnityEngine", "Screen");

		static int GetWidth() 
		{
			METHOD(int(**)(), get_width);
			return get_width();
		}

		static int GetHeight() 
		{
			METHOD(int(**)(), get_height);
			return get_height();
		}
	};

	class Input 
	{
	public:
		CLASS("UnityEngine", "Input");

		static Vector3D GetMousePosition() 
		{
			METHOD(Vector3D(**)(), get_mousePosition);
			return get_mousePosition();
		}
	};

	class Type 
	{
	public:
		CLASS("UnityEngine", "Type");

		static Type* GetType(const char* typeName) 
		{
			String* string = (String*)StringConverter::ToUnicode(typeName).c_str();

			METHOD(Type * (**)(String*), GetType);
			return GetType(string);
		}
	};

	class Quaternion
	{
	public:
		CLASS("UnityEngine", "Quaternion");

		float x;
		float y;
		float z;
		float w;

		static Quaternion LookRotation(Vector3D forward)
		{
			METHOD(Quaternion(**)(Vector3D), LookRotation);
			return LookRotation(forward);
		}

		static Quaternion RotateTowards(Quaternion from, Quaternion to, float maxDegreesDelta)
		{
			METHOD(Quaternion(**)(Quaternion, Quaternion, float), RotateTowards);
			return RotateTowards(from, to, maxDegreesDelta);
		}

		Vector3D GetEulerAngles()
		{
			METHOD(Vector3D(**)(Quaternion*), get_eulerAngles);
			return get_eulerAngles(this);
		}
	};

	class Transform
	{
	public:
		CLASS("UnityEngine", "Transform");

		Vector3D GetPosition()
		{
			METHOD(Vector3D(**) (Transform*), get_position);
			return get_position(this);
		}

		void SetPosition(Vector3D position)
		{
			METHOD(void(**)(Transform*, Vector3D), set_position);
			set_position(this, position);
		}

		Vector3D GetRight()
		{
			METHOD(Vector3D(**) (Transform*), get_right);
			return get_right(this);
		}

		Vector3D GetForward()
		{
			METHOD(Vector3D(**) (Transform*), get_forward);
			return get_forward(this);
		}

		Vector3D GetUp()
		{
			METHOD(Vector3D(**) (Transform*), get_up);
			return get_up(this);
		}

		Vector3D GetEulerAngles()
		{
			METHOD(Vector3D(**) (Transform*), get_eulerAngles);
			return get_eulerAngles(this);
		}

		void SetEulerAngles(Vector3D eulerAngles)
		{
			METHOD(void(**)(Transform*, Vector3D), set_eulerAngles);
			set_eulerAngles(this, eulerAngles);
		}

		Quaternion GetRotation()
		{
			METHOD(Quaternion(**) (Transform*), get_rotation);
			return get_rotation(this);
		}

		void SetRotation(Quaternion rotation)
		{
			METHOD(void(**)(Transform*, Quaternion), set_rotation);
			set_rotation(this, rotation);
		}

		Vector3D InverseTransformPoint(Vector3D position)
		{
			METHOD(Vector3D(**) (Transform*, Vector3D), InverseTransformPoint);
			return InverseTransformPoint(this, position);
		}

		Vector3D InverseTransformDirection(Vector3D direction)
		{
			METHOD(Vector3D(**) (Transform*, Vector3D), InverseTransformDirection);
			return InverseTransformDirection(this, direction);
		}

		void LookAt(Vector3D worldPosition)
		{
			METHOD(void(**)(Transform*, Vector3D), LookAt);
			LookAt(this, worldPosition);
		}
	};

	class Component;
	class GameObject : public Transform
	{
	public:
		CLASS("UnityEngine", "GameObject");

		Transform* GetTransform()
		{
			METHOD(Transform * (**)(GameObject*), get_transform);
			return get_transform(this);
		}

		Component* AddComponent(Type* componentType)
		{
			METHOD(Component * (**)(GameObject*, Type*), AddComponent);
			return AddComponent(this, componentType);
		}
	};

	class Component : public GameObject {
	public:
		CLASS("UnityEngine", "Component");

		GameObject* GetGameObject()
		{
			METHOD(GameObject * (**)(Component*), get_gameObject);
			return get_gameObject(this);
		}

		Transform* GetTransform()
		{
			METHOD(Transform * (**)(Component*), get_transform);
			return get_transform(this);
		}
	};

	class Camera : public Component
	{
	public:
		CLASS("UnityEngine", "Camera");

		static Camera* GetCamera()
		{
			METHOD(Camera*(**)(), get_main);
			return get_main();
		}

		Vector3D WorldToScreenPoint(Vector3D pos)
		{
			static auto WorldToScreenPoint = *reinterpret_cast<Vector3D(**)(Camera*, Vector3D)>(StaticClass()->GetMethodFromName("WorldToScreenPoint", 1));
			return WorldToScreenPoint(this, pos);
		}

		Vector2D WorldToScreenPointFixed(Vector3D position)
		{
			int screenHeight = Screen::GetHeight();
			Vector3D fixedPoint = WorldToScreenPoint(position);
			fixedPoint.y = screenHeight - fixedPoint.y;

			if (fixedPoint.z < 0)
				return Vector2D(0.f, 0.f);

			return Vector2D(fixedPoint.x, fixedPoint.y);
		}
	};
}