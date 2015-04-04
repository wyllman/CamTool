/**
 * @file    globalConf.h
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Directivas de preprocesador y componentes globales
 *
 * @section DESCRIPTION
 * @details
 *
 * Definida macro TEST_CHECKING para la compilación y
 * ejecución de los test.
 */
#ifndef GLOBALCONF_H
#define GLOBALCONF_H

/**
 * Se define la macro TEST_CHECKING para controlar el
 * uso de CppUnit (TDD) a nivel de compilación.
 *
 * Poner a false para desactivar las pruebas unitarias.
 */
#define TEST_CHECKING false

/**
 * Se define la macro CONSOLE_LINE_WIDTH para controlar
 * el número de caracteres que se van a mostrar por línea
 * en la consola o terminal.
 */
#define CONSOLE_LINE_WITH 65


#endif // GLOBALCONF_H
