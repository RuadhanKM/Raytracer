class render {
	public:
		double vsx; 
		double vsy;
		
		int ssh;
		int ssv;
		
		float EPSILON = 0.000001;
		
		std::vector<tri> objs = {};
		std::vector<cube*> cubes = {};
		std::vector<light*> lights = {};
		
		COORD topLeft;
		HANDLE hOut;
		
		std::string grayscale[5] = {"..", "**", "FF", "##", "@@"}; 
		
		render(double x, double y) {
			hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_CURSOR_INFO     cursorInfo;
			GetConsoleCursorInfo(hOut, &cursorInfo);
			cursorInfo.bVisible = false;
			SetConsoleCursorInfo(hOut, &cursorInfo);
			CONSOLE_SCREEN_BUFFER_INFO cbsi;
			GetConsoleScreenBufferInfo(hOut, &cbsi);
			topLeft = cbsi.dwCursorPosition;
			SetConsoleCursorPosition(hOut, topLeft);
			RECT desktop;
			const HWND hDesktop = GetDesktopWindow();
			GetWindowRect(hDesktop, &desktop);
			ssh = desktop.right;
			ssv = desktop.bottom;
			
			vsx = x;
			vsy = y;
		}
	
		void renderFrame(camera cam) {
			SetConsoleCursorPosition(hOut, topLeft);
			
			std::vector<tri> allObjs = objs;
			for (cube* cp : cubes) {
				cube c = *cp;
				
				c.getFaces();
				for (tri cface : c.faces) {
					allObjs.push_back(cface);
				}
			}
			
			std::string fins;
			for (double y=vsy/2; y>-vsy/2; --y){
				for (double x=-vsx/2; x<vsx/2; ++x){
					double lightness = 0;
					int lightnessInt = 0;
					bool pixelUp = false;
					
					vec3 nc(x/(vsx/2), y/(vsx/2), cam.fov);
					nc = cam.rotate(nc);
					
					vec3 fc = nc * 1000;
					
					nc = nc + cam.pos;
					fc = fc + cam.pos;
					
					double closestPoint = 1000;
					
					for (tri t : allObjs) {
						// Check for intersection 
							vec3 e0 = t.b - t.a;
							vec3 e1 = t.c - t.a;

							vec3 dir = fc - nc;
							vec3 dir_norm = dir.normalize();

							vec3 h = dir_norm.cross(e1);
							const float a = e0.dot(h);
							if (a > -EPSILON && a < EPSILON) {continue;}
							vec3 s = nc - t.a;
							const float f = 1.0f / a;
							const float u = f * s.dot(h);
							if (u < 0.0f || u > 1.0f) {continue;}
							vec3 q = s.cross(e0);
							const float v = f * dir_norm.dot(q);
							if (v < 0.0f || u + v > 1.0f) {continue;}
							const float tb = f * e1.dot(q);
						// Check for intersection 

						if (tb > EPSILON && tb < sqrtf(dir.dot(dir))) {
							vec3 point = nc + dir_norm * tb;
							vec3 relPoint = point - cam.pos;
							if (relPoint.mag() < closestPoint) {
								closestPoint = relPoint.mag();
							
							
								
								for (light* lp : lights) {
									light l = *lp;
									
									vec3 norm = t.normal().normalize();
									vec3 lightDir = (l.pos - point).normalize();
									
									double diffuse = norm.dot(lightDir);
									diffuse *= l.intensity;
									diffuse = std::max(diffuse, 0.0);
									
									lightness = diffuse;
								}
								
								
								//lightness = 1/(point - cam.pos).mag() * 30;
								
								
								lightnessInt = std::round(std::min(std::max(lightness, 0.0), 4.0));
								pixelUp = true;
							}
						}
					}
					
					if (pixelUp) {
						fins += grayscale[lightnessInt];
					} else {
						fins += "  ";
					}
				}
				fins += "\n";
			}
			
			std::cout << fins;
		}
};