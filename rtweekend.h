#ifndef RTWEEKEND_H
# define RTWEEKEND_H

#include <math.h>
#include <stdlib.h> // rand, RAND_MAX utilizados para generar numeros aleatorios
#include "vec3.h"
#define PI 3.1415926535897932385
#define PI 3.1415926535897932385



static inline double degrees_to_radians(double degrees) {
	return degrees * PI / 180.0;
}


// Numero real aleatorio en [0,1)
// rand() genera un numero aleatorio entre 0 y RAND_MAX
// Al dividir por (RAND_MAX + 1.0 ) se obtiene un numero entre [0,1)
static inline double random_double(void) {
	return rand() / (RAND_MAX + 1.0 );
}


// Numero real aleatorio en [min, max)
static inline double random_double_range(double min, double max) {
	return min + (max - min) * random_double ();
}

// Recorta x al intervalo [min, max]
// La funcion clamp obliga a x estar dentro de cierto intervalo
static inline double clamp(double x, double min, double max) {
	if (x < min) return min;
	if (x > max) return max;
	return x;
}


// Vector con componentes aleatorios
static inline vec3 vec3_random_range(double min, double max) {
	return v3(random_double_range(min, max), 
		random_double_range(min, max),
		random_double_range(min, max));
}

// Vector unitario con direccion uniformemente aleatoria
static inline vec3 random_unit_vector(void) {
	while (1) {
		vec3 p = vec3_random_range(-1,1);
		double lensq = vec3_length_squared(p);
		if (1e-160 < lensq && lensq <= 1.0)  // dentro de la esfera y no degenerado
			return vec3_div(p, sqrt(lensq));
	}
}


// Vector aleatorio en el hemisferio de la normal (una alternativa)
static inline vec3 random_on_hemisphere(vec3 normal) {
	vec3 on_unit = random_unit_vector();
	return (vec3_dot(on_unit, normal) > 0.0) ? on_unit : vec3_neg(on_unit);

}

// ¿Es el vector practicamente cero? (lo usaremos proximamente)
static inline int vec3_near_zero(vec3 v) {
	double s = 1e-8;
	return (fabs(v.x) < s) && (fabs(v.y) < s) && (fabs(v.z) < s);
}




#endif

