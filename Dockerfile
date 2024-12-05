    FROM gcc:latest

    # Install tini for signal handling
    RUN apt-get update && apt-get install -y tini

    WORKDIR /app

    COPY . /app

    RUN g++ -std=c++17 -o part1 src/*.cpp

    CMD ["./part1"]


