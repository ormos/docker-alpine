git clone https://github.com/scality/S3 S3

## Alpine microcontainer with Java

This is a micro docker container based on Alpine 3.4 with different node.js

### Examples

This images are build on elvido/alpine .

#### starting the container and showing the java version

	docker run -ti elvido/alpine-node node --version

This will start the container with a normal shell, no cron or other systems are started

#### docker-entrypoint.sh as example
```shell
#!/bin/sh

# set -e stops the execution of a script if a command or pipeline has an error
set -e

if [[ "$ACCESS_KEY" && "$SECRET_KEY" ]]; then
    sed -i "s/accessKeyDocker/$ACCESS_KEY/" ./conf/authdata.json
    sed -i "s/verySecretKeyDocker/$SECRET_KEY/" ./conf/authdata.json
    echo "Access key and secret key have been modified successfully"
fi

if [[ "$HOST_NAME" ]]; then
    sed -i "s/s3.docker.test/$HOST_NAME/" ./config.json
    echo "Host name has been modified to $HOST_NAME"
fi

if [[ "$LOG_LEVEL" ]]; then
    if [[ "$LOG_LEVEL" == "info" || "$LOG_LEVEL" == "debug" || "$LOG_LEVEL" == "trace" ]]; then
        sed -i "s/\"logLevel\": \"info\"/\"logLevel\": \"$LOG_LEVEL\"/" ./config.json
        echo "Log level has been modified to $LOG_LEVEL"
    else
        echo "The log level you provided is incorrect (info/debug/trace)"
    fi
fi

exec "$@"
```