class vec3 {
	public:
		float x;
		float y;
		float z;
		
		vec3(float xs, float ys, float zs) {
			x = xs;
			y = ys;
			z = zs;
		}
		vec3(float s) {
			x = s;
			y = s;
			z = s;
		}
		vec3() {
			x = 0;
			y = 0;
			z = 0;
		}
		
		float dot(const vec3 & b) {
			return x * b.x + y * b.y + z * b.z;
		}

		vec3 cross(const vec3 & b) {
			return vec3(
				y * b.z - z * b.y,
				z * b.x - x * b.z,
				x * b.y - y * b.x
			);
		}

		vec3 normalize() {
			const float s = 1.0f / sqrtf(vec3::x * vec3::x + vec3::y * vec3::y + vec3::z * vec3::z);
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
		vec3 operator*(const float s) {
			vec3 newVec(x * s, y * s, z * s);			return newVec;
		}
		vec3 operator/(const vec3& v) {
			vec3 newVec(x / v.x, y / v.y, z / v.z);		return newVec;
		}
		vec3 operator/(const float s) {
			vec3 newVec(x / s, y / s, z / s);			return newVec;
		}
		
		friend std::ostream& operator<<(std::ostream& os, const vec3& v)
		{
			os << v.x << ' ' << v.y << ' ' << v.z;
			return os;
		}
};