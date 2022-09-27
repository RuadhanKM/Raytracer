class tri {
	public:
		vec3 a;
		vec3 b;
		vec3 c;
		vec3 color;
		
		tri(vec3 as, vec3 bs, vec3 cs, vec3 colors) {
			a = as;
			b = bs;
			c = cs;
			color = colors;
		}
		tri() {
			a = vec3();
			b = vec3();
			c = vec3();
			color = vec3();
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