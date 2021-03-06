
# Orbit

OpenFrameworks + SuperCollider

## Introducción

Orbit es una exploración promovida desde PiranhaLab que se adscribe al paradigma de la programación al vuelo o live coding. Algunos antecedentes/desarrollos amigos que inspiran a Orbit son: CineVivo, Hydra y principalmente, Fluxus. Surge de la curiosidad por explorar audio y video simultáneamente. 

Del encuentro entre Orbit y SuperCollider ha surgido la motivación de utilizar funciones inicialmente concebidas para audio, como control para ordenar y manipular objetos en un entorno tridimensional. La mayor parte de esto es trabajo pendiente. El performance colaborativo y la visualización de información en un ensamble en red es otra de los objetivos de Orbit. 

Es posible controlar Orbit por medio de [PiranhaLib](https://github.com/rggtrn/PiranhaLib) y en general, por medio del protocolo OSC. También es posible controlar Orbit desde la ventana: basta teclear un poco sobre la ventana para introducir caracteres que pueden ser instrucciones.

Un proyecto paralelo intercambia funciones y estética con Orbit: [ofhawc](https://github.com/EmilioOcelotl/ofhawc)

### Orbit en acción 

[RGGTRN - moombahcode++geom](https://vimeo.com/289901460)

[Marianne Teixido - fragmentos](https://vimeo.com/294708631)

## Instalación

Orbit requiere una versión compilada de OF (se recomienda la versión v0.10.1)y los siguientes addons: [ofxCenteredTrueTypeFont](https://github.com/armadillu/ofxCenteredTrueTypeFont), [ofxPostGlitch](https://github.com/maxillacult/ofxPostGlitch) y una rama específica de la extensión [ofxHapPlayer](https://github.com/bangnoise/ofxHapPlayer):

Para instalar el códec Hap: https://github.com/Vidvox/hap-qt-codec/releases/

`$ git clone https://github.com/bangnoise/ofxHapPlayer`

`$ cd addons/ofxHapPlayer`

`$ git checkout libavformat-OF-0.9`

## Control en ventana

La sintáxis del control en ventana varía según la instrucción. En todos los casos, la instrucción empieza con una acción. Ej. load 1 samplehap (donde load es la instrucción para cargar un video, 1 es la pista en la que el video será cargado y samplehap es el nombre del archivo sin extensión).

Una versión detallada de las instrucciones se puede encontrar en la carpeta /bin/data/Orbit.txt

## Control OSC

Es posible controlar los parámetros de Orbit con [PiranhaLib](https://github.com/rggtrn/PiranhaLib).

PirS.start("127.0.0.1", 5612) // Para iniciar en modo local

PirV // acciones de video ej: PirV.load

## Videos en Hap

La conversión de videos es posible con ffmpeg. En macOS es posible instalar FFmpeg con soporte para hap con [brew](https://brew.sh/index_es):

`brew install ffmpeg --with-snappy`

* Para convertir videos en Hap

`ffmpeg -i yourSourceFile.mov -c:v hap outputName.mov`

* Para convertir videos en Hap Aplha

`ffmpeg -i yourSourceFile.mov -c:v hap -format hap_alpha outputName.mov`

* Para instrucciones más detalladas en inglés: https://gist.github.com/dlublin/e4585b872dd136ae88b2aa51a6a89aac

## Problemas y algunas soluciones

En Linux y con versiones anteriores a v0.10.1, la cámara tiene un comportamiento extraño. En v0.10.1 esto no sucede. 

El nombre de los archivos cargados (video o modelos) no debe contener caracteres en mayúsculas. 

No hay acentos. 
