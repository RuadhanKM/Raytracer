class square {
	public:
		double size;
		vec3 pos;
		vec3 rot;
		vec3 color;
		
		std::vector<tri> faces = {};
	
		square(vec3 p, double s, vec3 r, vec3 c) {
			size = s;
			pos = p;
			rot = r;
			color = c;
			
			getFaces();
		}
		
		void getFaces() {
			faces = {};
			
			vec3 P1(pos.x + size, pos.y + size, pos.z);
			vec3 P2(pos.x - size, pos.y - size, pos.z);
			vec3 P3(pos.x - size, pos.y + size, pos.z);
			
			vec3 P4(pos.x + size, pos.y + size, pos.z);
			vec3 P5(pos.x + size, pos.y - size, pos.z);
			vec3 P6(pos.x - size, pos.y - size, pos.z);
			
			P1 = P1.rotate(pos, rot);
			P2 = P2.rotate(pos, rot);
			P3 = P3.rotate(pos, rot);
			
			P4 = P4.rotate(pos, rot);
			P5 = P5.rotate(pos, rot);
			P6 = P6.rotate(pos, rot);
			
			tri F1(P1, P2, P3, color);
			tri F2(P4, P5, P6, color);
			faces.push_back(F1);
			faces.push_back(F2);
		}
};