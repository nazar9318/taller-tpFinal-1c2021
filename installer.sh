# citamos el trabajo practico argentum en la pagina de la catedra
# https://github.com/mauro7x/argentum

function waitingInputMessage() {
    echo "-------------------------------------------------"
    printf "> Ingrese una opción: "
}

function initialMessage () {
    clear
    echo "================================================="
    echo "=                COUNTER STRIKE 2D              ="
    echo "================================================="
    echo ""
}

function helpMessage() {
    echo "Opciones de instalación:"
    echo "  d: instala dependencias necesarias."
    echo "  i: instala el juego (no se instalan dependencias)."
    echo "  a: instala todo (dependencias y juego)."
    echo ""
    echo "Otras opciones:"
    echo "  h: muestra este mensaje."
    echo "  m: manual de usuario."
    echo "  q: cerrar."
    echo ""
}

function unknownInput() {
    echo "Opción desconocida (ingrese 'h' para ayuda, 'q' para salir)."
    echo ""
}

function userManual() {
    echo "=== MANUAL DE USUARIO ==="
    echo "Instalación"
    echo "  * Para comenzar a jugar, es necesario instalar dependencias y el juego een sí. Seleccionando la opción 'a' del menú, se realizará este proceso de forma automática."
    echo "  * Las dependencias que se instalarán serán las necesarias para utilizar la librería gráfica SDL, y CMake para la compilación."
    echo ""
    echo "Ejecución"
    echo "  * Servidor: './server' desde la carpeta build generada o './server ruta_configuraciones'. "
    echo "  * Cliente: corriendo './client' se abrirá el juego."
    echo ""

    echo "Configuración"
    echo "  * Para configurar el cliente, se debe modificar el archivo ClientConfiguration.yaml."
    echo "  * Para configurar el servidor, se puede modificar el archivo Configuration.yaml."
    echo ""
}

#------------------------------------------------------------------------------
# Compilación e instalación

function build() {
    sudo rm -rf build
    mkdir build
    cd build
    cmake -DUSR=YES ..
}

function installDependencies() {
    echo "=== INSTALACIÓN DE DEPENDENCIAS ==="
    echo ""
    echo ">> Instalando 'g++'..."
    sudo apt install g++
    echo ""
    echo ">> Instalando 'cmake'..."
    sudo apt-get install cmake
    echo ""
    echo ">> Instalando 'libsdl2-dev'..."
    sudo apt-get install libsdl2-dev
    echo ""
    echo ">> Instalando 'libsdl2-image-dev'..."
    sudo apt-get install libsdl2-image-dev
    echo ""
    echo ">> Instalando 'libsdl2-ttf-dev'..."
    sudo apt-get install libsdl2-ttf-dev
    echo ""
    echo ">> Instalando 'libsdl2-mixer-dev'..."
    sudo apt-get install libsdl2-mixer-dev
    echo ""
    echo ">> Instalando 'libsdl2-gfx-dev'..."
    sudo apt-get install libsdl2-gfx-dev
    echo ""
    echo ">> Instalando 'libsdl2-mixer-dev'..."
    sudo apt-get install libyaml-cpp-dev
    echo ""
    echo ">> Instalando 'qt5'..."
    sudo apt-get install qtcreator
    sudo apt-get install qt5-default
    echo ""
    echo "Instalación de dependencias finalizada."
    echo ""
}

function installGame() {
    echo "=== INSTALACIÓN DEL JUEGO ==="
    build
    sudo make install -j4
    echo ""
    echo "Instalación del juego finalizada."
    echo ""
}

function all() {
    installDependencies
    installGame
}



#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# Loop ppal

# exit when any command fails

initialMessage
helpMessage
waitingInputMessage

while :
do
    read OPTION
    case $OPTION in
        d)
            echo ""
            installDependencies
            waitingInputMessage
        ;;
        i)
            echo ""
            installGame
            waitingInputMessage
        ;;
        a)
            echo ""
            installDependencies
            installGame
            waitingInputMessage
        ;;
        h)
            echo ""
            helpMessage
            waitingInputMessage
        ;;
        m)
            echo ""
            userManual
            waitingInputMessage
        ;;
        q)
            echo ""
            echo "Adiós!"
            echo "-------------------------------------------------"
            exit 0
        ;;
        *)
            echo ""
            unknownInput
            waitingInputMessage
        ;;
    esac
done

#------------------------------------------------------------------------------
