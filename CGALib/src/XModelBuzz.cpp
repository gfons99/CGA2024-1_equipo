#include "Headers/XModelBuzz.h"

// class XModelBuzz
// {
// private:
//     /* data */
// public:
//     XModelBuzz(/* args */);
//     ~XModelBuzz();
// };

XModelBuzz::XModelBuzz(/* args */)
{
    glm::mat4 modelMatrix = glm::mat4(1.0f);

    float rotHead = 0.0;
    float rotLeftArm = 0.0;
    float rotLeftForeArm = 0.0;
    float rotLeftHand = 0.0;

    int indexFrameJoints = 0;
    int indexFrameJointsNext = 1;
    float interpolationJoints = 0.0;
    int maxNumPasosJoints = 20;
    int numPasosJoints = 0;
    int indexFrame = 0;
    int indexFrameNext = 1;
    float interpolation = 0.0;
    int maxNumPasos = 200;
    int numPasos = 0;
}

XModelBuzz::~XModelBuzz()
{
}

void XModelBuzz::xLoadModel(Shader shaderMulLighting)
{
    // Model Buzz
    modelHead.loadModel("../models/buzz/buzzlightyHead.obj");
    modelLeftArm.loadModel("../models/buzz/buzzlightyLeftArm.obj");
    modelLeftForeArm.loadModel("../models/buzz/buzzlightyLeftForearm.obj");
    modelLeftHand.loadModel("../models/buzz/buzzlightyLeftHand.obj");
    modelRightArm.loadModel("../models/buzz/buzzlightyRightArm.obj");
    modelRightForeArm.loadModel("../models/buzz/buzzlightyRightForearm.obj");
    modelRightHand.loadModel("../models/buzz/buzzlightyRightHand.obj");
    modelTorso.loadModel("../models/buzz/buzzlightyTorso.obj");
    modelLeftWing1.loadModel("../models/buzz/buzzlightyLeftWing1.obj");
    modelLeftWing2.loadModel("../models/buzz/buzzlightyLeftWing2.obj");
    modelRightWing1.loadModel("../models/buzz/buzzlightyRightWing1.obj");
    modelRightWing2.loadModel("../models/buzz/buzzlightyRightWing2.obj");
    modelHip.loadModel("../models/buzz/buzzlightyHip.obj");
    modelLeftThigh.loadModel("../models/buzz/buzzlightyLeftThigh.obj");
    modelLeftCalft.loadModel("../models/buzz/buzzlightyLeftCalf.obj");
    modelLeftFoot.loadModel("../models/buzz/buzzlightyLeftFoot.obj");
    modelRightThigh.loadModel("../models/buzz/buzzlightyRightThigh.obj");
    modelRightCalft.loadModel("../models/buzz/buzzlightyRightCalf.obj");
    modelRightFoot.loadModel("../models/buzz/buzzlightyRightFoot.obj");

    modelHead.setShader(&shaderMulLighting);
    modelLeftArm.setShader(&shaderMulLighting);
    modelLeftForeArm.setShader(&shaderMulLighting);
    modelLeftHand.setShader(&shaderMulLighting);
    modelRightArm.setShader(&shaderMulLighting);
    modelRightForeArm.setShader(&shaderMulLighting);
    modelRightHand.setShader(&shaderMulLighting);
    modelTorso.setShader(&shaderMulLighting);
    modelLeftWing1.setShader(&shaderMulLighting);
    modelLeftWing2.setShader(&shaderMulLighting);
    modelRightWing1.setShader(&shaderMulLighting);
    modelRightWing2.setShader(&shaderMulLighting);
    modelHip.setShader(&shaderMulLighting);
    modelLeftThigh.setShader(&shaderMulLighting);
    modelLeftCalft.setShader(&shaderMulLighting);
    modelLeftFoot.setShader(&shaderMulLighting);
    modelRightThigh.setShader(&shaderMulLighting);
    modelRightCalft.setShader(&shaderMulLighting);
    modelRightFoot.setShader(&shaderMulLighting);
}

void XModelBuzz::xDestroyModel()
{
    modelHead.destroy();
    modelLeftArm.destroy();
    modelLeftForeArm.destroy();
    modelLeftHand.destroy();
    modelRightArm.destroy();
    modelRightForeArm.destroy();
    modelRightHand.destroy();
    modelTorso.destroy();
    modelLeftWing1.destroy();
    modelLeftWing2.destroy();
    modelRightWing1.destroy();
    modelRightWing2.destroy();
    modelHip.destroy();
    modelLeftThigh.destroy();
    modelLeftCalft.destroy();
    modelLeftFoot.destroy();
    modelRightThigh.destroy();
    modelRightCalft.destroy();
    modelRightFoot.destroy();
}

void XModelBuzz::xSetKeyFramesJoints(std::vector<std::vector<float>> KFJ)
{
    keyFramesJoints = KFJ;
}
void XModelBuzz::xSetKeyFrames(std::vector<std::vector<glm::mat4>> KF)
{
    keyFrames = KF;
}

void XModelBuzz::xMovementsArti(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE &&
        glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        rotHead += 0.02;
    else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS &&
             glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        rotHead -= 0.02;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE &&
        glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        rotLeftArm += 0.02;
    else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS &&
             glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        rotLeftArm -= 0.02;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE &&
        glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
        rotRightArm += 0.02;
    else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS &&
             glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
        rotRightArm -= 0.02;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE &&
        glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
        rotLeftHand += 0.02;
    else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS &&
             glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
        rotLeftHand -= 0.02;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE &&
        glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
        rotRightHand += 0.02;
    else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS &&
             glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
        rotRightHand -= 0.02;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE &&
        glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
        rotLeftLeg += 0.02;
    else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS &&
             glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
        rotLeftLeg -= 0.02;
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE &&
        glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
        rotRightLeg += 0.02;
    else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS &&
             glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
        rotRightLeg -= 0.02;
}

void XModelBuzz::xMovementsFull(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        modelMatrix = glm::rotate(modelMatrix, 0.02f, glm::vec3(0, 1, 0));
    else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        modelMatrix = glm::rotate(modelMatrix, -0.02f, glm::vec3(0, 1, 0));
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        modelMatrix = glm::translate(modelMatrix, glm::vec3(-0.02, 0.0, 0.0));
    else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        modelMatrix = glm::translate(modelMatrix, glm::vec3(0.02, 0.0, 0.0));
}

void XModelBuzz::xSetModelMatrix(glm::vec3 punto)
{
    modelMatrix = glm::translate(modelMatrix, punto);
}

void XModelBuzz::xRenderModel()
{
    glm::mat4 modelMatrixBody = glm::mat4(modelMatrix);
    modelMatrixBody = glm::scale(modelMatrixBody, glm::vec3(3.f));
    modelTorso.render(modelMatrixBody);

    glm::mat4 modelMatrixHead = glm::mat4(modelMatrixBody);
    modelMatrixHead = glm::rotate(modelMatrixHead, rotHead, glm::vec3(0, 1, 0));
    modelHead.render(modelMatrixHead);

    glm::mat4 modelMatrixHip = glm::mat4(modelMatrixBody);
    modelHip.render(modelMatrixHip);

    glm::mat4 modelMatrixLeftArm = glm::mat4(modelMatrixBody);
    modelMatrixLeftArm = glm::translate(
        modelMatrixLeftArm, glm::vec3(0.177885, 0.58335, -0.026702));
    modelMatrixLeftArm = glm::rotate(
        modelMatrixLeftArm, rotLeftArm, glm::vec3(1.0, 0.0, 0.0));
    modelMatrixLeftArm = glm::translate(
        modelMatrixLeftArm, glm::vec3(-0.177885, -0.58335, 0.026702));
    modelLeftArm.render(modelMatrixLeftArm);

    glm::mat4 modelMatrixLeftForeArm = glm::mat4(modelMatrixLeftArm);
    modelMatrixLeftForeArm = glm::rotate(
        modelMatrixLeftForeArm, rotLeftForeArm, glm::vec3(1.0, 0.0, 0.0));
    modelLeftForeArm.render(modelMatrixLeftForeArm);

    glm::mat4 modelMatrixLeftHand = glm::mat4(modelMatrixLeftForeArm);
    modelMatrixLeftHand = glm::rotate(
        modelMatrixLeftHand, rotLeftHand, glm::vec3(1.0, 0.0, 0.0));
    modelLeftHand.render(modelMatrixLeftHand);
}