class light {
	public:
		vec3 pos;
		double intensity;
		
		light(vec3 p, double i) {
			pos = p;
			intensity = i;
		}
};