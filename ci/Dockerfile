FROM debian:buster
ENV CI=1
COPY ./install-deps.sh /
RUN bash -xe install-deps.sh
WORKDIR /ws
