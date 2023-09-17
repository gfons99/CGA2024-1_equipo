#ifndef XMODELBUZZ_H_
#define XMODELBUZZ_H_

// GLFW include
#include <GLFW/glfw3.h>

// GLM include
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Headers/Model.h"

class XModelBuzz
{
private:
    // Partes del modelo
    Model modelHead;

    Model modelLeftArm;
    Model modelLeftForeArm;
    Model modelLeftHand;

    Model modelRightArm;
    Model modelRightForeArm;
    Model modelRightHand;

    Model modelTorso;
    Model modelLeftWing1;
    Model modelLeftWing2;

    Model modelRightWing1;
    Model modelRightWing2;

    Model modelHip;
    Model modelLeftThigh;
    Model modelLeftCalft;
    Model modelLeftFoot;

    Model modelRightThigh;
    Model modelRightCalft;
    Model modelRightFoot;

    // Matrix principal
    glm::mat4 modelMatrix;

    // Variables de rotación de las artiulaciones
    float rotHead;
    float rotLeftArm;
    float rotLeftForeArm;
    float rotLeftHand;
    float rotRightArm;
    float rotRightForeArm;
    float rotRightHand;
    float rotTorso;
    float rotLeftWing1;
    float rotLeftWing2;
    float rotRightWing1;
    float rotRightWing2;
    float rotHip;
    // float rotLeftThigh;
    // float rotLeftCalft;
    // float rotLeftFoot;
    float rotLeftLeg;
    // float rotRightThigh;
    // float rotRightCalft;
    // float rotRightFoot;
    float rotRightLeg;

    // Joints interpolations Buzz
    std::vector<std::vector<float>> keyFramesJoints;
    std::vector<std::vector<glm::mat4>> keyFrames;
    int indexFrameJoints;
    int indexFrameJointsNext;
    float interpolationJoints;
    int maxNumPasosJoints;
    int numPasosJoints;
    int indexFrame;
    int indexFrameNext;
    float interpolation;
    int maxNumPasos;
    int numPasos;

    // Variables donde se guardan las matrices de cada articulacion por 1 frame
    std::vector<float> matrixSaveKFJ;
    std::vector<glm::mat4> matrixSaveKF;

public:
    XModelBuzz(/* args */);
    ~XModelBuzz();

    void xLoadModel(Shader shaderMulLighting);
    void xDestroyModel();

    void xSetKeyFramesJoints(std::vector<std::vector<float>> KFJ);
    void xSetKeyFrames(std::vector<std::vector<glm::mat4>> KF);

    void xMovementsArti(GLFWwindow *window);
    void xMovementsFull(GLFWwindow *window);

    void xSetModelMatrix(glm::vec3 punto);
    void xRenderModel();
};

// XModelBuzz::XModelBuzz(/* args */)
// {
// }

// XModelBuzz::~XModelBuzz()
// {
// }
#endif // XMODELBUZZ_H_