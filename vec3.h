class vec3 {
	public:
		double x;
		double y;
		double z;
		
		vec3(double xs, double ys, double zs) {
			x = xs;
			y = ys;
			z = zs;
		}
		vec3(double s) {
			x = s;
			y = s;
			z = s;
		}
		vec3() {
			x = 0;
			y = 0;
			z = 0;
		}
		
		double dot(const vec3 & b) {
			return x * b.x + y * b.y + z * b.z;
		}
		
		double mag() {
			return sqrt(x * x + y * y + z * z);
		}

		vec3 cross(const vec3 & b) {
			return vec3(
				y * b.z - z * b.y,
				z * b.x - x * b.z,
				x * b.y - y * b.x
			);
		}

		vec3 normalize() {
			const double s = 1.0f / sqrt(x * x + y * y + z * z);
			return vec3(x * s, y * s, z * s);
		}
		
		vec3 operator+(const vec3& v) {
			vec3 newVec(x + v.x, y + v.y, z + v.z);		return newVec;
		}
		vec3 operator-(const vec3& v) {
			vec3 newVec(x - v.x, y - v.y, z - v.z);		return newVec;
		}
		vec3 operator*(const vec3& v) {
			vec3 newVec(x * v.x, y * v.y, z * v.z);		return newVec;
		}
		vec3 operator*(const double s) {
			vec3 newVec(x * s, y * s, z * s);			return newVec;
		}
		vec3 operator/(const vec3& v) {
			vec3 newVec(x / v.x, y / v.y, z / v.z);		return newVec;
		}
		vec3 operator/(const double s) {
			vec3 newVec(x / s, y / s, z / s);			return newVec;
		}
		
		friend std::ostream& operator<<(std::ostream& os, const vec3& v)
		{
			os << v.x << ' ' << v.y << ' ' << v.z;
			return os;
		}
		
		vec3 rotate(vec3 about, vec3 euler) {
			vec3 point = *this - about;
			vec3 newPoint;
			vec3 radRot = euler * 0.017453292519943;
			
			// The reason for newpoint instead of just setting point immidetly is because each axis rotation is applied
			// sequentually and is based off the rest, but the opporations in each axis rotation are independent
			
			if (euler.z != 0.0) {
				// Rotation about the z axis
				newPoint.x = point.x * cos(radRot.z) - point.y * sin(radRot.z);
				newPoint.y = point.x * sin(radRot.z) + point.y * cos(radRot.z);
				
				point.x = newPoint.x;
				point.y = newPoint.y;
			}
			
			if (euler.y != 0.0) {
				// Rotation about the y axis
				newPoint.x =  point.x * cos(radRot.y) + point.z * sin(radRot.y);
				newPoint.z = -point.x * sin(radRot.y) + point.z * cos(radRot.y);
				
				point.x = newPoint.x;
				point.z = newPoint.z;
			}
			
			if (euler.x != 0.0) {
				// Rotation about the x axis
				newPoint.y = point.y * cos(radRot.x) - point.z * sin(radRot.x);
				newPoint.z = point.y * sin(radRot.x) + point.z * cos(radRot.x);
				
				point.y = newPoint.y;
				point.z = newPoint.z;
			}
			
			point = point + about;
			
			return point;
		}
};