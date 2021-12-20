# EJ3 - Honeypot FTP - Taller de Programación I
Este trabajo práctico es un prototipo de un honeypot de un servidor FTP.
Mayores detalles se encuentran en el archivo `2019.02.ejercicio.3.ftp-pot.pdf` que fue el enunciado del ejercicio.



## Ejecución
### Servidor
Para correr el servidor se ejecuta:  
`$ ./server <puerto/servicio> <configuracion>`  
Donde:
* `<puerto>` es donde se escuchará a conexiones entrantes.  
* `<configuracion>` es un archivo de configuración que define variables que utilizará el servidor. Se proveen archivos de ejemplo con el nombre de `config.cfg` en la carpeta de Pruebas.  

### Cliente
Para inicarlo se ejecuta:  
`$ ./client <ip/hostname> <puerto/servicio>`  

Los comandos que puede ejecutar el cliente son los siguientes:  
* USER <username>: Envía un nombre de usuario para realizar login.  
* PASS <password>: Envía un password para el usuario.  
* SYST: Consulta información del sistema.  
* LIST: Consulta los archivos contenidos en el directorio actual.  
* HELP: Consulta los comandos disponibles.  
* PWD: Consulta el directorio actual.  
* MKD: Crea un directorio.  

## Realizado por 
* Manuel Sturla