##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=math
ConfigurationName      :=Debug
WorkspacePath          := "/Users/petebyhre/dev/projects/openMind"
ProjectPath            := "/Users/petebyhre/dev/projects/openMind/math"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Pete Byhre
Date                   :=2014-10-04
CodeLitePath           :="/Users/petebyhre/Library/Application Support/codelite"
LinkerName             :=/usr/bin/clang++ 
SharedObjectLinkerName :=/usr/bin/clang++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="math.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)$(WorkspacePath)/include  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)$(WorkspacePath)/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/clang++ 
CC       := /usr/bin/clang 
CXXFLAGS :=  -g -v  $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as 


##
## User defined environment variables
##
CodeLiteDir:=/Users/petebyhre/Downloads/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/InvalidCellException.cpp$(ObjectSuffix) $(IntermediateDirectory)/IncompatableMatrixException.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) $(Objects) $(ArLibs)
	@$(MakeDirCommand) "/Users/petebyhre/dev/projects/openMind/.build-debug"
	@echo rebuilt > "/Users/petebyhre/dev/projects/openMind/.build-debug/math"

./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/InvalidCellException.cpp$(ObjectSuffix): InvalidCellException.cpp $(IntermediateDirectory)/InvalidCellException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/petebyhre/dev/projects/openMind/math/InvalidCellException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/InvalidCellException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/InvalidCellException.cpp$(DependSuffix): InvalidCellException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/InvalidCellException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/InvalidCellException.cpp$(DependSuffix) -MM "InvalidCellException.cpp"

$(IntermediateDirectory)/InvalidCellException.cpp$(PreprocessSuffix): InvalidCellException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/InvalidCellException.cpp$(PreprocessSuffix) "InvalidCellException.cpp"

$(IntermediateDirectory)/IncompatableMatrixException.cpp$(ObjectSuffix): IncompatableMatrixException.cpp $(IntermediateDirectory)/IncompatableMatrixException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/petebyhre/dev/projects/openMind/math/IncompatableMatrixException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IncompatableMatrixException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IncompatableMatrixException.cpp$(DependSuffix): IncompatableMatrixException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IncompatableMatrixException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IncompatableMatrixException.cpp$(DependSuffix) -MM "IncompatableMatrixException.cpp"

$(IntermediateDirectory)/IncompatableMatrixException.cpp$(PreprocessSuffix): IncompatableMatrixException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IncompatableMatrixException.cpp$(PreprocessSuffix) "IncompatableMatrixException.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/math"


