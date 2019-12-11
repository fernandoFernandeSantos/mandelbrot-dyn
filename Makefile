
CXX=g++
EXEC=mandelbrot

CUDAPATH=/usr/local/cuda
NVCC=$(CUDAPATH)/bin/nvcc

#ARCH= -gencode arch=compute_35,code=[sm_35,compute_35] #Kepler
ARCH= -gencode arch=compute_70,code=[sm_70,compute_70] #Titan V
#ARCH+= -gencode arch=compute_72,code=[sm_72,compute_72] #XavierV
CXXFLAGS= -std=c++11 -O3 -fopenmp
INCLUDE= -I$(CUDAPATH)/include
LDFLAGS= -L$(CUDAPATH)/lib64 -lcudart  -lpng

OBJS=mandelbrot.o

all: $(EXEC)

$(EXEC): $(OBJS)  
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS) $(INCLUDE)

$(OBJDIR)%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE)
	
$(OBJDIR)%.o: %.cu $(DEPS)
	$(NVCC) $(ARCH) $(NVCCFLAGS) -c $< -o $@ $(INCLUDE)
	
clean:
	rm -f $(EXEC) *.o 