#include "scene.h"

#include <GL/glut.h>

#include <time.h>
#include <obj/load.h>
#include <obj/draw.h>

double ball_x=0;
double ball_y=0;
double ball_z=-5.2;
double ball_rotate=0;
double ball_rotate1=0;
int i =0;
double ball_moves=0;
double brightness=0;
double my_brightnesss=-2;

double tree1_moves=0;
double tree2_moves=0;
const Scene* scene;



void init_scene(Scene* scene)
{
   /* load_model(&(scene->mountain), "obj/ball.obj");
    scene->texture_mountain = load_texture("textures/ball.jpg"); 	*/
	
    load_model(&(scene->pine_tree1), "obj/kapu.obj");
 
	
	
    

    load_model(&(scene->ball), "obj/ball.obj");
    scene->texture_ball = load_texture("textures/ball.jpg"); 	
  	
	
    load_model(&(scene->ice), "obj/ice.obj");
    scene->texture_ice = load_texture("textures/kep1.jpg"); 
	scene->help = load_texture("textures/help.png"); 
	//scene->gol = load_texture("textures/kep1.png"); 

    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;
	
    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 6.0;
}

void set_lighting()
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f+brightness, 1.0f+brightness, 1.0f+brightness, 1.0f+brightness };
    float specular_light[] = { 1.0f+my_brightnesss, 1.0f+my_brightnesss, 1.0f+my_brightnesss, 1.0f+my_brightnesss };
    float position[] = { 40.0f, 20.0f, 10.0f, 2.0f };
 
	GLfloat light_position[] = {300, 0, -1000, 0.};
    GLfloat light_color[] = {0, 1, 0, 1};
	
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void update_lighting(Scene* scene, double value)
{
	brightness+=value;
	
}	

void my_light(int value){
	if(value==0){
			my_brightnesss=2;
	}	
	if(value==1){
			my_brightnesss=-2;
	}		
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
	
}

void draw_scene(const Scene* scene)
{
	glRotatef(90,1,0,0);
    set_material(&(scene->material));
    set_lighting();
	/*glBindTexture(GL_TEXTURE_2D, scene->texture_mountain);	
	
    draw_model(&(scene->mountain));*/
	
	glBindTexture(GL_TEXTURE_2D, scene->texture_ice);	
	glPushMatrix();	
		
		draw_model(&(scene->ice));
	glPopMatrix();	
	
	glBindTexture(GL_TEXTURE_2D, scene->texture_pinetree);
	glPushMatrix();
		glTranslatef(0.9,0.0,1+tree1_moves);
    draw_model(&(scene->pine_tree1));
	glPopMatrix();	
	
	glBindTexture(GL_TEXTURE_2D, scene->texture_pinetree);	
	glPushMatrix();
		glRotatef(180,0,1,0);
		glTranslatef(-0.9,0.0,-1.3+tree2_moves);
	draw_model(&(scene->pine_tree2));
	glPopMatrix();	

	glBindTexture(GL_TEXTURE_2D, scene->texture_ball);
	glPushMatrix();
	
			
			
				glRotatef(360+ball_rotate,0,1,0);
		glTranslatef(-2.9+ball_x,0+ball_y,1);
		
		draw_model(&(scene->ball));
	
	glPopMatrix();	
	
	glBindTexture(GL_TEXTURE_2D, scene->help);	
		
}

void ball_move(double time){
		
		/*if(ball_moves <0.054)
		{*/
	if(ball_y >= 0)
	{
	ball_y = ball_y+time/1.2;
	
		if(ball_y >=0.2){
			ball_y =0.18;
			ball_y =0.14;
			ball_y =0.12;
			ball_y =0.10;
			ball_y =0.08;
			ball_y =0.04;
			ball_y =0.02;
			ball_y =0;
			ball_y = (ball_y)*time/5;

	}
	}/*
	
			if(ball_x >=4)
			{
		
		
			ball_x=ball_x+time/120;
	ball_y=ball_y+time/10;
	ball_rotate=ball_rotate-time*10;
	ball_rotate1 = ball_rotate;
	
		if(ball_y>=3)
		{
			ball_x = ball_x+time/0.1;
			ball_y=ball_y+time/0.5;
			
		}
			}
		else{
		ball_x = ball_x+time/2;
			ball_y=ball_y+time/5;	
		}*/
		
}	
void ball_move2(double time){
	double szam=0;
	ball_x = ball_x+time/0.4;
	ball_y = 0.2;
			
	szam = ball_x+ball_y;

			if(szam >= 3.9)
			{
				
				ball_y = 0.2;
				ball_y = 0.19;
				ball_y = 0.18;
				ball_y = 0.17;
				ball_y = 0.16;
				ball_y = 0.15;
				ball_y = 0.12;
				ball_y = 0.10;
				ball_y = 0.08;
				ball_y = 0.04;
				ball_y = 0.00;
				ball_x = 4;
			}
}






void tree_move(double time){
	if(tree1_moves<0.054){
		tree1_moves+=time/100;
		tree2_moves+=time/100;
	}
}
void tree_move_back(double time){
	if(tree1_moves>0){
		tree1_moves-=time/100;
		tree2_moves-=time/100;
	}
}	

	
