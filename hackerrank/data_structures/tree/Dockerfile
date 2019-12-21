FROM opensuse/leap:15.2

RUN useradd --system -u ${LOCAL_USER_ID:-1000} build \
	&& zypper -n update \
	&& zypper -n in git-core ninja meson 
RUN zypper -n in gcc gcc-c++
RUN zypper -n in cmake

RUN git clone https://github.com/google/googletest.git /googletest

RUN cd /googletest \
	&& mkdir build \
	&& cd build \
	&& cmake /googletest \
	&& make \
	&& make install

USER build
VOLUME /code
WORKDIR /code
