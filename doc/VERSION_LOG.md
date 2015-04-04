Control de versiones y cambios.
==============================

- v 0.0.1:
  - Estructura inicial de archivos y carpetas (ventana principal QT).
  - En main.cpp crear ejemplo de catura de webCam usando OpenCv (sin QT).
  - Iniciar el control de versiones git con repositorio remoto en GitHub.
  - Integración del proyecto en la plataforma Travis CI (creación del archivo .travis.yml)
  - Instalación de las librerías de OpenCV, el compilador de QT y las librerías CppUnit en Travis.(.travis.yml)
  - Crear archivo .pro para travis.(CamTool.travis.pro)
  - Compilar el proyecto en travis usando el archivo .pro propio.(CamTool.travis.pro, .travis.yml)
  - Crear versión inicial de la documentación usando DoxyGen.(Archivo de configuración Doxyfile).
  - Crear la estructura inicial de la clase CameraController y sus expectativas.
  - Instalar en travis Xvfb(xserver) para las ejecuciones del programa.
  - Creación de la clase Base_spec como clase padre para todas las demás clases de las expectativas.
  - Implementación de la función obtainCamerasInfo() y las funciones adecuadas para vaciar memoria de los objetos
    de la clase CameraController.
  - Implementación de la función string obtainCamerasInfo() y sus expectativas iniciales.(La anterior función
    obtainCamerasInfo() se ha refactorizado a obtainCameras().
  - Implementada la función showMultipleLines(...) para la clase ConsoleView.
  - Refactorizando la clase CameraController para:
    - Tener un segundo array de cámaras como seleccionadas para otros usos.
    - Refactorizar las funciones básicas de la clase para hacerlas más generales.

- v 0.0.2:
  - Primera fase de la clase CameraController finalizada.
  - Refactorizado el codigo de main.cpp(ejecucion principal) a la clase ExecutionController:
    - Creadas las funciones cargar(...) y ejecutar(...)
  - Creada la primera version del splash screen en el controlador de ejecucion.


