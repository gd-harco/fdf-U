FROM devkitpro/devkitppc:latest
LABEL authors="gd-harco"
#
#
RUN apt-get update
RUN apt-get install -y wget
RUN apt-get install -y build-essential
RUN apt-get install -y gdb
RUN rm -rf /var/lib/apt/lists/*
#
#RUN wget https://apt.devkitpro.org/install-devkitpro-pacman
#RUN chmod +x ./install-devkitpro-pacman
#
#ENV DEBIAN_FRONTEND=noninteractive
#
#RUN yes |./install-devkitpro-pacman
#
#COPY ./launch.sh ./
#ENTRYPOINT ["bash", "./launch.sh"]
