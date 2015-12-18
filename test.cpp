#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include <string.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
//g++ test.cpp -LGL -lGL -lGLU -lglut -lGLEW -o test
#define VERTSIZE 36
float verts[37];
#define FACESIZE 30
int faces[31];

void readObj(float verts[], int faces[]) {
  int i = 0;
  int j = 0;
  puts("READING");
  FILE * obj = fopen("i.obj", "r");
  char lineHeader[80];
  int res;
  while (1) {
    res = fscanf(obj, "%s", lineHeader);
    if (res == EOF)
      break;
    if (strcmp(lineHeader, "v") == 0){
      fscanf(obj, "%f %f %f\n", &verts[i], &verts[i+1], &verts[i+2]);
      i+=3;
    }
    if (strcmp(lineHeader, "f") == 0){
      fscanf(obj, "%i %i %i\n", &faces[j], &faces[j+1], &faces[j+2]);
      j+=3; 
    }
  }
  fclose(obj);
}

void display(void) {
  static GLfloat angle = 0.0;
  static GLfloat blue = 1.0;
  static GLfloat green = 1.0;
  static GLfloat scale = 1.0;
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  GLfloat theta = M_PI*angle/180.0;
  float shiftY, shiftX;
  shiftY = .25*sin(theta);
  shiftX = .25*cos(theta);
  blue = .5*(sin(theta)+1);
  green = .5*(cos(theta)+1);
  scale = sin(theta);
  int i = 0;
  int v1, v2, v3;
  while (i<FACESIZE) {
    glColor3f(0,green,blue);
    v1 = 3*(faces[i]-1);
    v2 = 3*(faces[i+1]-1);
    v3 = 3*(faces[i+2]-1);
    glBegin(GL_TRIANGLES);
      glVertex3f(verts[v1]+shiftX,scale*(verts[v1+1])+shiftY,verts[v1+2]);
      glVertex3f(verts[v2]+shiftX,scale*(verts[v2+1])+shiftY,verts[v2+2]);
      glVertex3f(verts[v3]+shiftX,scale*(verts[v3+1])+shiftY,verts[v3+2]);
    glEnd();
    i+=3;
  }
  

  glFlush();
  glutSwapBuffers();

  angle += 1.0;

  glutPostRedisplay();
}

// void init () {
  // int x, y, w, h;
  // GLfloat buf[4];
  // glGetFloatv(GL_VIEWPORT,buf);
  // x = buf[0]; y = buf[1];
  // w = buf[2]; h = buf[3];
  // glViewport(x,y,w,h);
  // gluOrtho2D(-.5,-.5,w-.5,h-.5);
  // readObj();
// }

int main(int argc, char** argv) {
  readObj(verts, faces);
  // for (int i=0; i<36; i+=3){
  //   printf("%f %f %f\n", verts[i], verts[i+1], verts[i+2]);
  // }
  // for (int i=0; i<30; i+=3) {
  //   printf("%i %i %i\n", faces[i], faces[i+1], faces[i+2]);
  // }
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  glewInit();
  glutDisplayFunc(display); 
  glutMainLoop();
  return 0;
}