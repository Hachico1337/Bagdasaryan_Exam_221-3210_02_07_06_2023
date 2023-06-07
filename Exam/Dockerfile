FROM ubuntu:18.04

LABEL author="Bagdasaryan Artem"

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get install qt5-default qtbase5-dev qt5-qmake -y
RUN apt-get install build-essential -y

WORKDIR /221_3210_Bagdasaryan

COPY *.cpp /221_3210_Bagdasaryan
COPY *.h /221_3210_Bagdasaryan
COPY *.pro /221_3210_Bagdasaryan

RUN qmake hallserver.pro
RUN make

ENTRYPOINT ["./hallserver"]