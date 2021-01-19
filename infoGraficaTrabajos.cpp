//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#define STB_IMAGE_IMPLEMENTATION  
//#include <stb/stb_image.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include <learnopengl/shader_m.h>
//#include <learnopengl/camera.h>
//
//#include <iostream>
//#include <vector>
//using namespace std;
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void processInput(GLFWwindow* window);
//unsigned int loadTexture(const char* path);
//unsigned int loadCubemap(vector<std::string> faces);
//
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//// camera
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//bool firstMouse = true;
//float yaw = -90.0f; // yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
//float pitch = 0.0f;
//float lastX = 800.0f / 2.0;
//float lastY = 600.0 / 2.0;
//float fov = 45.0f;
//
//// timing
//float deltaTime = 0.0f; // time between current frame and last frame
//float lastFrame = 0.0f;
//
//// generamos un vector de luz (punto de luz) en el espacio 
//glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
//
//void TowerBase(glm::vec3 towerPos, Shader ourShader,int type);
//
//void TowerTop(glm::vec3 towerTopPos, Shader ourShader,int type);
//
//void WallDrawHorizontal(glm::vec3 wall, Shader ourShader);
//void WallDrawVertical(glm::vec3 wall, Shader ourShader);
//
//void MainBody(glm::vec3 bodyPos, Shader ourShader);
//
//
//int main()
//{
//    // glfw: initialize and configure
//    // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    // glfw window creation
//    // --------------------
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    glfwSetCursorPosCallback(window, mouse_callback);
//    glfwSetScrollCallback(window, scroll_callback);
//
//    // tell GLFW to capture our mouse
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // configure global opengl state
//    // -----------------------------
//    glEnable(GL_DEPTH_TEST);
//
//    // build and compile our shader zprogram
//    // ------------------------------------
//    Shader lightingShader("luzbasica.vs", "luzbasica.fs");
//    Shader lightCubeShader("luzcubo.vs", "luzcubo.fs");
//    Shader skyboxShader("skybox.vs", "skybox.fs");
//    Shader ourShader("camaraprrna.vs", "camaraprrona.fs");
//
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//    float vertices[] = {
//        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//    };
//
//    float skyboxVertices[] = {
//        // positions          
//        -1.0f,  1.0f, -1.0f,
//        -1.0f, -1.0f, -1.0f,
//         1.0f, -1.0f, -1.0f,
//         1.0f, -1.0f, -1.0f,
//         1.0f,  1.0f, -1.0f,
//        -1.0f,  1.0f, -1.0f,
//
//        -1.0f, -1.0f,  1.0f,
//        -1.0f, -1.0f, -1.0f,
//        -1.0f,  1.0f, -1.0f,
//        -1.0f,  1.0f, -1.0f,
//        -1.0f,  1.0f,  1.0f,
//        -1.0f, -1.0f,  1.0f,
//
//         1.0f, -1.0f, -1.0f,
//         1.0f, -1.0f,  1.0f,
//         1.0f,  1.0f,  1.0f,
//         1.0f,  1.0f,  1.0f,
//         1.0f,  1.0f, -1.0f,
//         1.0f, -1.0f, -1.0f,
//
//        -1.0f, -1.0f,  1.0f,
//        -1.0f,  1.0f,  1.0f,
//         1.0f,  1.0f,  1.0f,
//         1.0f,  1.0f,  1.0f,
//         1.0f, -1.0f,  1.0f,
//        -1.0f, -1.0f,  1.0f,
//
//        -1.0f,  1.0f, -1.0f,
//         1.0f,  1.0f, -1.0f,
//         1.0f,  1.0f,  1.0f,
//         1.0f,  1.0f,  1.0f,
//        -1.0f,  1.0f,  1.0f,
//        -1.0f,  1.0f, -1.0f,
//
//        -1.0f, -1.0f, -1.0f,
//        -1.0f, -1.0f,  1.0f,
//         1.0f, -1.0f, -1.0f,
//         1.0f, -1.0f, -1.0f,
//        -1.0f, -1.0f,  1.0f,
//         1.0f, -1.0f,  1.0f
//    };
//
//    // world space positions of our cubes
//
//    glm::vec3 castle = {
//        glm::vec3(0.0f,  0.0f, 0.0f),
//    };
//
//    float distanceTowers = 2.0f;
//
//    glm::vec3 tower1 = {
//       glm::vec3(-distanceTowers,  0.0f,  -distanceTowers)
//    };
//
//    glm::vec3 tower2 = {
//        glm::vec3(-distanceTowers,  0.0f,  0.0f)
//    };
//
//    glm::vec3 tower3 = {
//       glm::vec3(-distanceTowers,  0.0f,  distanceTowers)
//    };
//
//    glm::vec3 tower4 = {
//        glm::vec3(0,  0.0f, distanceTowers)
//    };
//
//    glm::vec3 tower5 = {
//       glm::vec3(distanceTowers,  0.0f,  distanceTowers)
//    };
//
//    glm::vec3 tower6 = {
//       glm::vec3(distanceTowers,  0.0f,  0.0f)
//    };
//
//    glm::vec3 tower7 = {
//        glm::vec3(distanceTowers,  0.0f,  -distanceTowers)
//    };
//
//    glm::vec3 tower8 = {
//        glm::vec3(0,  0.0f, -distanceTowers)
//    };
//
//    float distanceWalls = 2.0f;
//
//    glm::vec3 wall1 = {
//       glm::vec3(-distanceWalls,  0.0f, -distanceWalls+1),
//    };
//
//    glm::vec3 wall2 = {
//       glm::vec3(-distanceWalls,  0.0f,  distanceWalls-1),
//    };
//
//    glm::vec3 wall3 = {
//       glm::vec3(-distanceWalls+1,  0.0f,  distanceWalls),
//    };
//
//    glm::vec3 wall4 = {
//       glm::vec3(distanceWalls-1,  0.0f,  distanceWalls),
//    };
//
//    glm::vec3 wall5 = {
//       glm::vec3(distanceWalls,  0.0f, distanceWalls - 1),
//    };
//
//    glm::vec3 wall6 = {
//       glm::vec3(distanceWalls,  0.0f,  - distanceWalls + 1),
//    };
//
//    glm::vec3 wall7 = {
//       glm::vec3(distanceWalls - 1,  0.0f,  -distanceWalls),
//    };
//
//    glm::vec3 wall8 = {
//       glm::vec3(-distanceWalls + 1,  0.0f,  -distanceWalls),
//    };
//    
//    float thp = 0.6f;
//    float gapTop = .5f;
//
//    glm::vec3 topPosition1 = {
//        glm::vec3(-distanceTowers,  thp+gapTop,  -distanceTowers),
//    };
//
//    glm::vec3 topPosition2 = {
//       glm::vec3(-distanceTowers,  thp,  0.0),
//    };
//
//    glm::vec3 topPosition3 = {
//       glm::vec3(-distanceTowers,  thp+ gapTop,  distanceTowers),
//    };
//
//    glm::vec3 topPosition4 = {
//       glm::vec3(0,  thp,  distanceTowers),
//    };
//
//    glm::vec3 topPosition5 = {
//    glm::vec3(distanceTowers,  thp+ gapTop,  distanceTowers),
//    };
//
//    glm::vec3 topPosition6 = {
//       glm::vec3(distanceTowers,  thp,  0),
//    };
//
//    glm::vec3 topPosition7 = {
//       glm::vec3(distanceTowers,  thp+ gapTop,  -distanceTowers),
//    };
//
//    glm::vec3 topPosition8 = {
//       glm::vec3(0,  thp,  -distanceTowers),
//    };
//
//    float bh = 1.3f;
//    float bs = 0.65f;
//
//    float tipx = 2.0f;
//    float tipz = 2.0f;
//
//    glm::vec3 brickPos1[] = {
//        glm::vec3(tipx + -bs, bh, tipz + -bs),
//        glm::vec3(tipx + 0.0f, bh, tipz + -bs),
//        glm::vec3(tipx + bs, bh, tipz + bs),
//        glm::vec3(tipx + -bs, bh, tipz + bs),
//        glm::vec3(tipx + 0.0f, bh, tipz + bs),
//        glm::vec3(tipx + bs, bh, tipz + -bs),
//        glm::vec3(tipx + -bs, bh, tipz + 0.0f),
//        glm::vec3(tipx + bs, bh, tipz + 0.0f),
//    };
//
//    tipx = -2.0f;
//    tipz = -2.0f;
//
//    glm::vec3 brickPos2[] = {
//        glm::vec3(tipx + -bs, bh, tipz + -bs),
//        glm::vec3(tipx + 0.0f, bh, tipz + -bs),
//        glm::vec3(tipx + bs, bh, tipz + bs),
//        glm::vec3(tipx + -bs, bh, tipz + bs),
//        glm::vec3(tipx + 0.0f, bh, tipz + bs),
//        glm::vec3(tipx + bs, bh, tipz + -bs),
//        glm::vec3(tipx + -bs, bh, tipz + 0.0f),
//        glm::vec3(tipx + bs, bh, tipz + 0.0f),
//    };
//
//    tipx = -2.0f;
//    tipz = 2.0f;
//
//    glm::vec3 brickPos3[] = {
//        glm::vec3(tipx + -bs, bh, tipz + -bs),
//        glm::vec3(tipx + 0.0f, bh, tipz + -bs),
//        glm::vec3(tipx + bs, bh, tipz + bs),
//        glm::vec3(tipx + -bs, bh, tipz + bs),
//        glm::vec3(tipx + 0.0f, bh, tipz + bs),
//        glm::vec3(tipx + bs, bh, tipz + -bs),
//        glm::vec3(tipx + -bs, bh, tipz + 0.0f),
//        glm::vec3(tipx + bs, bh, tipz + 0.0f),
//    };
//
//    tipx = 2.0f;
//    tipz = -2.0f;
//
//    glm::vec3 brickPos4[] = {
//        glm::vec3(tipx + -bs, bh, tipz + -bs),
//        glm::vec3(tipx + 0.0f, bh, tipz + -bs),
//        glm::vec3(tipx + bs, bh, tipz + bs),
//        glm::vec3(tipx + -bs, bh, tipz + bs),
//        glm::vec3(tipx + 0.0f, bh, tipz + bs),
//        glm::vec3(tipx + bs, bh, tipz + -bs),
//        glm::vec3(tipx + -bs, bh, tipz + 0.0f),
//        glm::vec3(tipx + bs, bh, tipz + 0.0f),
//    };
//
//    tipx = 0.0f;
//    tipz = 0.0f;
//    bh = 1.2f;
//    bs = 0.4;
//
//    glm::vec3 brickPos5[] = {
//        glm::vec3(tipx + -bs, bh, tipz + -bs),
//        glm::vec3(tipx + 0.0f, bh, tipz + -bs),
//        glm::vec3(tipx + bs, bh, tipz + bs),
//        glm::vec3(tipx + -bs, bh, tipz + bs),
//        glm::vec3(tipx + 0.0f, bh, tipz + bs),
//        glm::vec3(tipx + bs, bh, tipz + -bs),
//        glm::vec3(tipx + -bs, bh, tipz + 0.0f),
//        glm::vec3(tipx + bs, bh, tipz + 0.0f),
//    };
//
//    unsigned int skyboxVAO, skyboxVBO;
//    glGenVertexArrays(1, &skyboxVAO);
//    glGenBuffers(1, &skyboxVBO);
//    glBindVertexArray(skyboxVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//
//    vector<std::string> faces
//    {
//        ("resources/textures/skybox/skybox/right.jpg"),
//        ("resources/textures/skybox/skybox/left.jpg"),
//        ("resources/textures/skybox/skybox/top.jpg"),
//        ("resources/textures/skybox/skybox/bottom.jpg"),
//        ("resources/textures/skybox/skybox/front.jpg"),
//        ("resources/textures/skybox/skybox/back.jpg")
//    };
//
//    //unsigned int cubemapTexture = loadCubemap(faces);
//
//    ////configuracion del shader
//    //skyboxShader.use();
//    //skyboxShader.setInt("skybox", 0);
//
//
//    unsigned int VBO, VAO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//
//    glBindVertexArray(VAO);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    // position attribute
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    // texture coord attribute
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//
//
//    // load and create a texture 
//    // -------------------------
//    unsigned int texture1, texture2;
//    // texture 1
//    // ---------
//    glGenTextures(1, &texture1);
//    glBindTexture(GL_TEXTURE_2D, texture1);
//    // set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//    int width, height, nrChannels;
//    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
//    unsigned char* data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//    // texture 2
//    // ---------
//    glGenTextures(1, &texture2);
//    glBindTexture(GL_TEXTURE_2D, texture2);
//    // set the texture wrapping parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    // set texture filtering parameters
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    // load image, create texture and generate mipmaps
//    data = stbi_load("resources/textures/awesomeface.png", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
//    // -------------------------------------------------------------------------------------------
//    ourShader.use();
//    ourShader.setInt("texture1", 0);
//    ourShader.setInt("texture2", 1);
//
//
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window))
//    {
//        // per-frame time logic
//        // --------------------
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        // input
//        // -----
//        processInput(window);
//
//        // render
//        // ------
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        // bind textures on corresponding texture units
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, texture1);
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, texture2);
//
//        // activate shader
//        ourShader.use();
//
//        // pass projection matrix to shader (note that in this case it could change every frame)
//        glm::mat4 projection = glm::perspective(glm::radians(fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//        ourShader.setMat4("projection", projection);
//
//        // camera/view transformation
//        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//        ourShader.setMat4("view", view);
//
//        // render boxes
//        glBindVertexArray(VAO);
//
//        float tS = 0.2f;
//        for (unsigned int i = 0; i < 10; i++)
//        {
//            // calculate the model matrix for each object and pass it to shader before drawing
//            glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//            glm::mat4 model2 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//
//            model = glm::translate(model, brickPos1[i]);
//            model = glm::scale(model, glm::vec3(tS, tS, tS));
//            ourShader.setMat4("model", model);
//
//            glDrawArrays(GL_TRIANGLES, 0, 400);
//        }
//        for (unsigned int i = 0; i < 10; i++)
//        {
//            // calculate the model matrix for each object and pass it to shader before drawing
//            glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//            glm::mat4 model2 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//        
//            model = glm::translate(model, brickPos2[i]);
//            model = glm::scale(model, glm::vec3(tS, tS, tS));
//            ourShader.setMat4("model", model);
//        
//            glDrawArrays(GL_TRIANGLES, 0, 400);
//        }
//        for (unsigned int i = 0; i < 10; i++)
//        {
//            // calculate the model matrix for each object and pass it to shader before drawing
//            glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//            glm::mat4 model2 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//        
//            model = glm::translate(model, brickPos3[i]);
//            model = glm::scale(model, glm::vec3(tS, tS, tS));
//            ourShader.setMat4("model", model);
//        
//            glDrawArrays(GL_TRIANGLES, 0, 400);
//        }
//        for (unsigned int i = 0; i < 10; i++)
//        {
//            // calculate the model matrix for each object and pass it to shader before drawing
//            glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//            glm::mat4 model2 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//        
//            model = glm::translate(model, brickPos4[i]);
//            model = glm::scale(model, glm::vec3(tS, tS, tS));
//            ourShader.setMat4("model", model);
//        
//            glDrawArrays(GL_TRIANGLES, 0, 400);
//        }
//        for (unsigned int i = 0; i < 10; i++)
//        {
//            // calculate the model matrix for each object and pass it to shader before drawing
//            glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//            glm::mat4 model2 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//        
//            model = glm::translate(model, brickPos5[i]);
//            model = glm::scale(model, glm::vec3(tS, tS, tS));
//            ourShader.setMat4("model", model);
//        
//            glDrawArrays(GL_TRIANGLES, 0, 400);
//        }
//
//        // MAIN BODY
//        MainBody(castle, ourShader);
//
//        // TOWER BASE
//
//        TowerBase(tower1, ourShader, 1);
//        TowerBase(tower2, ourShader, 0);
//        TowerBase(tower3, ourShader, 1);
//        TowerBase(tower4, ourShader, 0);
//        TowerBase(tower5, ourShader, 1);
//        TowerBase(tower6, ourShader, 0);
//        TowerBase(tower7, ourShader, 1);
//        TowerBase(tower8, ourShader, 0);
//
//        //TOP OF TOWER BASE
//
//        TowerTop(topPosition1, ourShader,0);
//        TowerTop(topPosition2, ourShader,1);
//        TowerTop(topPosition3, ourShader,0);
//        TowerTop(topPosition4, ourShader,1);
//        TowerTop(topPosition5, ourShader,0);
//        TowerTop(topPosition6, ourShader,1);
//        TowerTop(topPosition7, ourShader,0);
//        TowerTop(topPosition8, ourShader,1);
//
//        //WALLS
//        WallDrawVertical(wall1, ourShader);
//        WallDrawVertical(wall2, ourShader);
//        WallDrawHorizontal(wall3, ourShader);
//        WallDrawHorizontal(wall4, ourShader);
//        WallDrawVertical(wall5, ourShader);
//        WallDrawVertical(wall6, ourShader);
//        WallDrawHorizontal(wall7, ourShader);
//        WallDrawHorizontal(wall8, ourShader);
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // optional: de-allocate all resources once they've outlived their purpose:
//    // ------------------------------------------------------------------------
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteBuffers(1, &VBO);
//
//    // glfw: terminate, clearing all previously allocated GLFW resources.
//    // ------------------------------------------------------------------
//    glfwTerminate();
//    return 0;
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//    float cameraSpeed = 2.5 * deltaTime;
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        cameraPos += cameraSpeed * cameraFront;
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        cameraPos -= cameraSpeed * cameraFront;
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and 
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}
//
//// glfw: whenever the mouse moves, this callback is called
//// -------------------------------------------------------
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//
//    float xoffset = xpos - lastX;
//    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
//    lastX = xpos;
//    lastY = ypos;
//
//    float sensitivity = 0.1f; // change this value to your liking
//    xoffset *= sensitivity;
//    yoffset *= sensitivity;
//
//    yaw += xoffset;
//    pitch += yoffset;
//
//    // make sure that when pitch is out of bounds, screen doesn't get flipped
//    if (pitch > 89.0f)
//        pitch = 89.0f;
//    if (pitch < -89.0f)
//        pitch = -89.0f;
//
//    glm::vec3 front;
//    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//    front.y = sin(glm::radians(pitch));
//    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//    cameraFront = glm::normalize(front);
//}
//
//// glfw: whenever the mouse scroll wheel scrolls, this callback is called
//// ----------------------------------------------------------------------
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    fov -= (float)yoffset;
//    if (fov < 1.0f)
//        fov = 1.0f;
//    if (fov > 45.0f)
//        fov = 45.0f;
//}
//
//void MainBody(glm::vec3 bodyPos, Shader ourShader) {
//    float mS = 1.0f;
//
//    for (unsigned int i = 0; i < 10; i++)
//    {
//        // calculate the model matrix for each object and pass it to shader before drawing
//        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//
//        model = glm::translate(model, glm::vec3(bodyPos.x, bodyPos.y + 0.4f, bodyPos.z));
//        model = glm::scale(model, glm::vec3(mS, mS * 1.4f, mS));
//        ourShader.setMat4("model", model);
//
//        glDrawArrays(GL_TRIANGLES, 0, 400);
//    }
//}
//
//void TowerBase(glm::vec3 towerPos, Shader ourShader, int type) {
//    float bS;
//    float bH;
//    if (type == 0) {
//        bS = 0.8f;
//        bH = 1;
//    }
//    else {
//        bS = 1;
//        bH = 1.5;
//    }
//
//    for (unsigned int i = 0; i < 10; i++)
//    {
//        // calculate the model matrix for each object and pass it to shader before drawing
//        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//        if (type == 0) {
//            model = glm::translate(model, glm::vec3(towerPos.x, towerPos.y, towerPos.z));
//        }
//        else
//        {
//            model = glm::translate(model, glm::vec3(towerPos.x, towerPos.y+.3, towerPos.z));
//        }
//        model = glm::scale(model, glm::vec3(bS, bH, bS));
//        ourShader.setMat4("model", model);
//
//        glDrawArrays(GL_TRIANGLES, 0, 400);
//    }
//}
//
//void TowerTop(glm::vec3 towerPos, Shader ourShader,int type) {
//    float hs = 0.3f;
//    float bW;
//    if(type) {
//        bW = 1;
//    }
//    else
//    {
//        bW = 1.5;
//    }
//    for (unsigned int i = 0; i < 10; i++)
//    {
//        // calculate the model matrix for each object and pass it to shader before drawing
//        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//
//        model = glm::translate(model, glm::vec3(towerPos.x, towerPos.y, towerPos.z));
//        model = glm::scale(model, glm::vec3(bW, hs, bW));
//        ourShader.setMat4("model", model);
//
//        glDrawArrays(GL_TRIANGLES, 0, 400);
//    }
//}
//
//void WallDrawHorizontal(glm::vec3 wall, Shader ourShader) {
//    for (unsigned int i = 0; i < 10; i++)
//    {
//        // calculate the model matrix for each object and pass it to shader before drawing
//        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//
//        model = glm::translate(model, glm::vec3(wall.x, wall.y, wall.z));
//        model = glm::scale(model, glm::vec3(1.5f, 0.9f, 0.2f));
//
//        ourShader.setMat4("model", model);
//
//        glDrawArrays(GL_TRIANGLES, 0, 400);
//    }
//}
//
//void WallDrawVertical(glm::vec3 wall, Shader ourShader) {
//    for (unsigned int i = 0; i < 10; i++)
//    {
//        // calculate the model matrix for each object and pass it to shader before drawing
//        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
//
//        model = glm::translate(model, glm::vec3(wall.x, wall.y, wall.z));
//        model = glm::scale(model, glm::vec3(0.2f, 0.9f, 1.5f));
//
//        ourShader.setMat4("model", model);
//
//        glDrawArrays(GL_TRIANGLES, 0, 400);
//    }
//}