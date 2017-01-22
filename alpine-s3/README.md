git clone https://github.com/scality/S3 S3

## Alpine microcontainer with Java

This is a micro docker container based on Alpine 3.4 with different node.js

### Examples

This images are build on elvido/alpine .

#### starting the container and showing the java version

	docker run -ti elvido/alpine-node node --version

This will start the container with a normal shell, no cron or other systems are started

