FROM elvido/alpine

LABEL maintainer="elvido <ralf.hofmann@elvido.net>"

RUN apk --no-cache upgrade --update && \
    apk --no-cache add --quiet ca-certificates && \
    apk --no-cache add --quiet curl sudo

RUN adduser -g '' -D  z z && \
    echo 'z ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

# Cache some packages
RUN apk --no-cache add --quiet \
    git \
    zsh \
    tmux \
    vim \
    wget curl \
    jq \
    iftop htop \
    tree \
    unzip

USER z
WORKDIR /home/z

CMD ["zsh"]
