# taller-tpFinal-1c2021


**Compilar y ejecutar**


Para compilar el Servidor y el Cliente ejecutar las siguientes lineas:

~~~{.bash}
mkdir build
cd build
cmake ..
make
~~~


Para ejecutarlos desde la carpeta build, las siguientes:

~~~{.bash}
./server port

./client host port
~~~


**Instalar yaml**

~~~{.bash}
sudo apt-get install libyaml-cpp-dev
~~~

# ¡Bienvenido al Counter Strike 2D!
A continuación, le indicamos cómo jugar:

El juego cuenta con 3 aplicaciones: Editor, Servidor y Cliente.

- Servidor: Simplemente ejecutelo y ya podrá crear varias partidas con la aplicación del cliente.

- Editor:
Con esta aplicación podrá crear distintos mapas en los que jugar.
Cada mapa puede contar con distinta cantidad de baldosas, cajas, armas, zonas de bomba y zonas de spawn de jugadores.
	Ítems que se pueden usar para crear un mapa:
		- Baldosa: Simplemente es el piso básico del escenario, en éste los personajes van a poder
		caminar en el juego. Además, en el editor, sólo en este tipo de ítem se pueden colocar armas y zonas de spawn.
		- Caja: Este ítem impide que un personaje camine sobre él, no se puede colocar ningún otro ítem sobre él.
		- Arma: Representa las armas que los personajes van a poder usar, sólo puede haber un arma sobre cada baldosa.
		- Zona de bomba: Representa la zona donde los terroristas van a poder colocar las bombas, y los counter van a tener que 			vigilar para poder desactivarlas. No puede colocarse nada sobre éste ítem.
		- Zona de Spawn: Representa la zona donde van a poder spawnear los personajes, sean terroristas o counter,
		sólo puede haber uno por baldosa
	Botones que ayudan a crear el mapa:
		- Save: permite guardar el mapa en configuración YAML.
		- Load: Abre un archivo de formato YAML y llena el mapa acorde.
		- Clean All: Borra todo el mapa en caso que quiera empezar de nuevo.
		- Clean Selected: En caso que quiera borrar sólo algunos ítems del mapa,
		haga click con el botón izquierdo del mousse, esto marcará al ítem con líneas punteadas en sus bordes.
		Luego, presione este botón y todos los ítems seleccionados. Para seleccionar más de un ítem,
		haga click manteniendo apretado CTRL+IZQ.

Detalles y condiciones de uso: todos los archivos deben guardarse en formato '.yaml' para poder ser usados como mapa.
El formato de mapa busca ser siempre de forma rectangular,
por ende si a la hora de crear el mapa, si este tiene alguna zona vacío adentro,
ésta se completará con una caja negra a la hora de guardarlo (para poder verlo,
cree un mapa cualquiera con zonas vacías, guárdelo y vuelva a cargarlo).
Además, para evitar que los personajes se salgan del mapa,
al guardar se rodea todo el mapa creado de cajas negras.

- Cliente:
		Ventana de inicio: Al ejecutarlo le aparecerá una ventana que le pedirá su nombre,
		éste debe tener más de 3 caracteres para poder avanzar (no puede jugar sin nombre).

		Ventana de Crear/Unirse: Le permitirá elegir entre Crear una nueva partida o unirse a otra en espera.
		-Si elige Crear, le aparecerá una lista de mapas (creados por el Editor) para poder seleccionar,
		una vez seleccionado, deberá ponerle un nombre a la partida, de más de 3 caracteres.
		Luego, le aparecerá la lista de jugadores que se vayan uniendo a la partida que ha creado,
		de click en el botón 'Comenzar Juego' para que comience la partida, ésto sólo funcionará
		si hay por lo menos un jugador que se haya unido a su partida, de lo contrario deberá esperar.
		-Si elige Unirse, le aparecerá la lista de partidas disponibles, haga click
		en la que quiera unirse y espera a que el Creador de la partida de comienzo.
		
Asignación de las teclas del juego:
		-W: Moverse hacia arriba.
		-A: Moverse hacia la izquierda.
		-D: Moverse hacia la derecha.
		-S: Moverse hacia abajo.
		(Nota: la dirección del movimiento es respecto al mapa, no respecto hacia donde está apuntanto el personaje.
		-C: Cambiar al arma siguiente de entre las disponibles.
		-SPACE: Recoger arma, si ya tiene un arma secundaria equipada, ésta última será droppeada.
		-Click Izquierdo del mousse: Disparar con el arma equipada hacia donde el personaje está apuntando.
		-Q: Colocar bomba, debe mantenerlo apretado hasta que el conteo de tiempo termine para que funcione correctamente.
		-E: Desactivar bomba, debe mantenerlo apretado hasta que el conteo de tiempo termine para que funcione correctamente.
