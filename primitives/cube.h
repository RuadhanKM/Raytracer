class cube {
	public:
		double size;
		vec3 pos;
		vec3 rot;
		vec3 color;
		
		std::vector<tri> faces = {};
	
		cube(vec3 p, double s, vec3 r, vec3 c) {
			size = s;
			pos = p;
			rot = r;
			color = c;
			
			getFaces();
		}
		
		void getFaces() {
			faces = {};
			
			square front(	vec3(pos.x, pos.y, pos.z + size)	.rotate(pos, rot), size, vec3(0,180,0) 		+ rot, color);
			square back(	vec3(pos.x, pos.y, pos.z - size)	.rotate(pos, rot), size, vec3() 			+ rot, color);
			
			square top(		vec3(pos.x, pos.y + size, pos.z)	.rotate(pos, rot), size, vec3(90, 0, 0) 	+ rot, color);
			square bottom(	vec3(pos.x, pos.y - size, pos.z)	.rotate(pos, rot), size, vec3(-90, 0, 0) 	+ rot, color);
			
			square left(	vec3(pos.x + size, pos.y, pos.z)	.rotate(pos, rot), size, vec3(0, -90, 0) 	+ rot, color);
			square right(	vec3(pos.x - size, pos.y, pos.z)	.rotate(pos, rot), size, vec3(0, 90, 0) 	+ rot, color);
			
			front.getFaces();
			back.getFaces();
			top.getFaces();
			bottom.getFaces();
			left.getFaces();
			right.getFaces();
			
			faces.push_back(front.faces[0]);
			faces.push_back(front.faces[1]);
			faces.push_back(back.faces[0]);
			faces.push_back(back.faces[1]);
			
			faces.push_back(top.faces[0]);
			faces.push_back(top.faces[1]);
			faces.push_back(bottom.faces[0]);
			faces.push_back(bottom.faces[1]);
			
			faces.push_back(left.faces[0]);
			faces.push_back(left.faces[1]);
			faces.push_back(right.faces[0]);
			faces.push_back(right.faces[1]);
		}
};