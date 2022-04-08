#include <iostream>
#include <vector>
#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <math.h>

#include "vec3.h"
#include "light.h"
#include "tri.h"

#include "primitives/cube.h"

#include "camera.h"
#include "render.h"

int main(int argc, char *argv[]) {
	render viewport(94, 53);
	camera cam(vec3(), vec3(), 1);
	
	vec3 a(0, 0, 100);
	vec3 b(10, 0, 100);
	vec3 c(10, 10, 100);
	tri t(a, b, c);
	viewport.objs.push_back(&t);
	vec3 a2(0, 0, 100);
	vec3 b2(0, 10, 100);
	vec3 c2(10, 10, 100);
	tri t2(a2, b2, c2);
	viewport.objs.push_back(&t2);
	
	light l(vec3(5, 5, 90), 1);
	viewport.lights.push_back(&l);
	
	POINT mp;
	
	double sens = 0.2;
	
	while (1) {
		GetCursorPos(&mp);
		vec3 mpDelta(mp.x - viewport.ssh/2, mp.y - viewport.ssv/2, 0);
		SetCursorPos(viewport.ssh/2, viewport.ssv/2);
		
		if (GetKeyState('W') & 0x8000) {cam.pos = cam.pos + cam.rotate(vec3(0,0,1));}
		if (GetKeyState('S') & 0x8000) {cam.pos = cam.pos - cam.rotate(vec3(0,0,1));}
		if (GetKeyState('A') & 0x8000) {cam.pos = cam.pos - cam.rotate(vec3(1,0,0));}
		if (GetKeyState('D') & 0x8000) {cam.pos = cam.pos + cam.rotate(vec3(1,0,0));}
		
		cam.rot.y += mpDelta.x * sens;
		cam.rot.x += mpDelta.y * sens;
		
		std::cout << cam.pos << "\n";
		std::cout << cam.rot << "\n";
		std::cout << mpDelta;
		
		viewport.renderFrame(cam);
	}
	
	return 0;
}