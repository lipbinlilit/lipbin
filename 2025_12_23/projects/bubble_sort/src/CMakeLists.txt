target_sources(${LIBRARY_NAME}
	PRIVATE
		bubble.cpp
	PUBLIC
		bubble.h
)

target_include_directories(${LIBRARY_NAME} PUBLIC
	${PROJECT_SOURCE_DIR}/src
)