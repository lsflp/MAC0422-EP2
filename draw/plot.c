#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>
#include <math.h>

double w;
double h;
int pause = 1;
double delta = 0.1;

void window_size_callback(GLFWwindow* window, int width, int height) {
    h = height;
    w = width;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    else if (key == GLFW_KEY_F && action == GLFW_PRESS)
        delta /= 1.2;
    else if (key == GLFW_KEY_S && action == GLFW_PRESS)
        delta *= 1.2;
    else if (key == GLFW_KEY_P && action == GLFW_PRESS)
        pause = 1 - pause;
}

void Torus2d( float inner, float outer, unsigned int pts) {
    unsigned int i;
    glBegin( GL_QUAD_STRIP );
    for(i = 0; i <= pts; ++i ) {
        float angle = ( i / (float)pts ) * M_PI * 2.0f;
        glVertex2f( inner * cos( angle ), inner * sin( angle ) );
        glVertex2f( outer * cos( angle ), outer * sin( angle ) );
    }
    glEnd();
}

void bici(int pista, int posi, int team, int d, int v) {
    float i;

    float inner;
    float outer;

    if (pista == -1 || posi == -1) return;

    if (team) glColor3ub( 255, v/16.0*255, 0 );
    else glColor3ub( 0, v/16.0*255, 255 );

    if (pista) {
        inner = 3.6;
        outer = 3.9;
    } else {
        inner = 3.1;
        outer = 3.4;
    }

    glBegin( GL_QUAD_STRIP );
    for(i = posi+0.2; i <= posi+1.8; i += 0.2 ) {
        float angle = ( i / (float)(2*d) ) * M_PI * 2.0f;
        glVertex2f( inner * cos( angle ), inner * sin( angle ) );
        glVertex2f( outer * cos( angle ), outer * sin( angle ) );
    }

    glEnd();
}

int main(void) {
    char line[64];
    int d, n, x;
    GLFWwindow* window;
    w = 640;
    h = 480;

    float time_next;

    char tmp;
    int N, T, P, S, E, D, V;


    scanf("%d %d", &d, &n);

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(w, h, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetWindowSizeCallback(window, window_size_callback);
    glfwSetKeyCallback(window, key_callback);

    time_next = glfwGetTime () + 1.0;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        if (time_next < glfwGetTime () && pause) {
            /* Render here */
            glClear(GL_COLOR_BUFFER_BIT);

            glMatrixMode( GL_PROJECTION );
            glLoadIdentity();
            double ar = w / h;
            glOrtho( -4 * ar, 4 * ar, -4, 4, -1, 1);

            glMatrixMode( GL_MODELVIEW );
            glLoadIdentity();

            glColor3ub( 100, 100, 100 );
            Torus2d( 3, 3.5, d*2);


            glColor3ub( 130, 130, 130 );
            Torus2d( 3.5, 4, d*2);

            fflush(stdout);

        
            while ((fgets(line, sizeof line, stdin) != NULL) && (line[0] != '\n') && (line[0] != 'C')) {
                /* parse the read line with sscanf */
                if (sscanf(line, "N %4d, T %d, P %6d, S %2d, E %2d, D %6d, V %2d\n", &N, &T, &P, &S, &E, &D, &V) > 0) {
                    bici(E, P, T, d, V);
                    //printf("%d %d %d %d %d %d %d\n", N, T, P, S, E, D, V);
                    fflush(stdout);
                }
            }
            time_next = glfwGetTime () + delta;
        
            /* Swap front and back buffers */
            glfwSwapBuffers(window);

        }

        /* Poll for and process events */
        glfwPollEvents();
        /*sleep(1);*/
    }

    glfwTerminate();
    return 0;
}