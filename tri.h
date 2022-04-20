class tri {
	public:
		vec3 a;
		vec3 b;
		vec3 c;
		
		tri(vec3 as, vec3 bs, vec3 cs) {
			a = as;
			b = bs;
			c = cs;
		}
		tri() {
			a = vec3();
			b = vec3();
			c = vec3();
		}
		
		vec3 normal() {
			vec3 edge1 = b-a;
			vec3 edge2 = c-a;
			
			return edge1.cross(edge2).normalize();
		}
		
		friend std::ostream& operator<<(std::ostream& os, const tri& t)
		{
			os << t.a << '\n' << t.b << '\n' << t.c;
			return os;
		}
};