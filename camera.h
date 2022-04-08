class camera {
	public:
		vec3 pos;
		double fov;
		vec3 rot;
		
		camera(vec3 p, vec3 r, double f) {
			pos = p;
			rot = r;
			fov = f;
		}
		
		vec3 getRadRot() {
			return vec3(rot.x * 0.017453292519943, rot.y * 0.017453292519943, rot.z * 0.017453292519943);
		}
		vec3 rotate(vec3 point) {			
			// Rotation about the x axis
			point.y = point.y * cos(getRadRot().x) - point.z * sin(getRadRot().x);
			point.z = point.y * sin(getRadRot().x) + point.z * cos(getRadRot().x);
			
			// Rotation about the y axis
			point.x =  point.x * cos(getRadRot().y) + point.z * sin(getRadRot().y);
			point.z = -point.x * sin(getRadRot().y) + point.z * cos(getRadRot().y);
			
			// Rotation about the z axis
			point.x = point.x * cos(getRadRot().z) - point.y * sin(getRadRot().z);
			point.y = point.x * sin(getRadRot().z) + point.y * cos(getRadRot().z);
			
			return point;
		}
};