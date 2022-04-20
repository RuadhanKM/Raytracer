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
			return rot * 0.017453292519943;
		}
		vec3 rotate(vec3 point) {
			vec3 radRot = getRadRot();
			vec3 newPoint;
			
			// Rotation about the x axis
			newPoint.y = point.y * cos(radRot.x) - point.z * sin(radRot.x);
			newPoint.z = point.y * sin(radRot.x) + point.z * cos(radRot.x);
			point.y = newPoint.y;
			point.z = newPoint.z;
			
			// Rotation about the y axis
			newPoint.x =  point.x * cos(radRot.y) + point.z * sin(radRot.y);
			newPoint.z = -point.x * sin(radRot.y) + point.z * cos(radRot.y);
			point.x = newPoint.x;
			point.z = newPoint.z;
			
			// Rotation about the z axis
			newPoint.x = point.x * cos(radRot.z) - point.y * sin(radRot.z);
			newPoint.y = point.x * sin(radRot.z) + point.y * cos(radRot.z);
			point.x = newPoint.x;
			point.y = newPoint.y;
			
			return point;
		}
};