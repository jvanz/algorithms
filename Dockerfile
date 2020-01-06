FROM opensuse/leap:15.2

RUN useradd --system -u ${LOCAL_USER_ID:-1000} build \
	&& zypper -n update \
	&& zypper -n in git-core ninja gcc gcc-c++ cmake clang python3-pip

# updates certificates
RUN update-ca-certificates

# install the latest meson
RUN pip3 install meson

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
