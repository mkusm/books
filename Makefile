run:
	docker run -p 9999:9999 --mount type=bind,source="$(shell pwd)",target=/home cling

build:
	docker build -t cling .
