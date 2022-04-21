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
#include "camera.h"

#include "primitives/square.h"
#include "primitives/cube.h"

#include "render.h"

int main(int argc, char *argv[]) {
	render viewport(128, 72);
	camera cam(vec3(), vec3(), 1);
	
	cube c2(vec3(40, 0, 100), 10, vec3());
	viewport.cubes.push_back(&c2);
	
	square floor(vec3(0,-10,0), 1000, vec3(90,0,0));
	viewport.squares.push_back(&floor);
	

	light l(vec3(0, 25, 70), 8);
	viewport.lights.push_back(&l);
	
	double sens = 0.2;
	POINT mp;
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
		
		
		
		c2.rot.x += 3;
		c2.getFaces();
		
		if (GetKeyState(VK_RIGHT) & 0x8000) {l.pos = l.pos + vec3(1,0,0);}
		if (GetKeyState(VK_LEFT) & 0x8000) {l.pos = l.pos - vec3(1,0,0);}
		if (GetKeyState(VK_UP) & 0x8000) {l.pos = l.pos - vec3(0,0,1);}
		if (GetKeyState(VK_DOWN) & 0x8000) {l.pos = l.pos + vec3(0,0,1);}
		
		
		
		viewport.renderFrame(cam);
	}
	
	return 0;
}