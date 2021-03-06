#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "matrix4f.h"
#include "vector3f.h"
#include "camera.h"

class Transform
{
public:
	static inline Camera& GetCamera() { return *s_camera; }
	static inline void SetCamera(Camera& camera) { s_camera = &camera; }
	static void SetProjection(float fov, float width, float height, float zNear, float zFar);
	
	Transform(Vector3f pos = Vector3f(0,0,0), Vector3f rot = Vector3f(0,0,0), Vector3f scale = Vector3f(1,1,1));
	~Transform();

	Matrix4f GetTransformation();
	Matrix4f GetProjectedTransformation();

	inline Vector3f& GetPos() { return m_pos; }
	inline Vector3f& GetRot() { return m_rot; }
	inline Vector3f& GetScale() { return m_scale; }

	inline void SetPos(const Vector3f& pos) { m_pos = pos; }
	inline void SetRot(const Vector3f& rot) { m_rot = rot; }
	inline void SetScale(const Vector3f& scale) { m_scale = scale; }
protected:
private:
	static Camera* s_camera;

	static float m_fov;
	static float m_width;
	static float m_height;
	static float m_zNear;
	static float m_zFar;

	Vector3f m_pos;
	Vector3f m_rot;
	Vector3f m_scale;
};

#endif
