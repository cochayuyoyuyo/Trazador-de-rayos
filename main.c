#include <stdio.h>
#include "vec3.h"
#include "color.h"
#include "ray.h"
#include <math.h>
#include "hittable.h"
#include "rtweekend.h"
#include "material.h"
#include "camera.h"


int main(void) { 
   
   
   
   
   


   // Materiales 
   material mat_ground = { LAMBERTIAN, v3(0.0, 0.8, 0.0), 0, 0};
   material mat_center = { LAMBERTIAN, v3(0.1, 0.2, 0.5), 0, 0};
   material mat_left = { DIELECTRIC, v3(0, 0, 0), 0, 1.50};
   material mat_bubble = {DIELECTRIC, v3(0, 0, 0), 0, 1.0 / 1.50}; 
   material mat_right = { METAL, v3(0, 0.2,0.6 ), 1.0, 0};
  

// Esferas: cada una apunta a su material con el
   sphere spheres[] = {
	{ v3(0,  -100.5, -1), 100.0, &mat_ground },
        { v3(0, -0, -1.2),  0.5, &mat_center },
	{ v3(-1, 0, -1), 0.5, &mat_left },
	{ v3(-1, 0, -1), 0.4, &mat_bubble },
	{ v3(1, 0, -1), 0.5, &mat_right},
	
   };
   hittable_list world = { spheres, 5 };


// Camara: fija los parametros y renderiza
   camera cam;
   cam.defocus_angle = 10.0;
   cam.focus_dist = 3.4;
   cam.aspect_ratio = 16.0/9.0;
   cam.image_width = 400;
   cam.samples_per_pixel = 100;
   cam.max_depth= 50;
   cam.vfov = 20;
// Posicion de camara
   cam.lookfrom = v3(-2, 2, 1);
   cam.lookat = v3(0, 0, -1);
   cam.vup = v3(0, 1, 0);
   
   
// Modificacion
// w -> writte  
//   FILE* f;
//   char nombre_archivo[20];
   
//   for(int i = 1; i< 10; i++) {
//   	snprintf(nombre_archivo, sizeof(nombre_archivo),
//   		"imagen_%05d.ppm", i);
   		
//   	cam.lookfrom = v3(1-i, 3*i, 1);
   	
  
   	
   	   	
   	
//   	f = fopen(nombre_archivo, "w");
//   	 camera_render(f, &cam, world);


	camera_render(&cam, world);
   	
   	
   
  
//  fclose(f);
   return 0;

}





