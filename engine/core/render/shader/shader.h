#include <string>
class Shader
{
public:
	unsigned int id;
	std::string vertexShaderPath;
	std::string fragShaderPath;
	std::string vertexCode;
	std::string fragCode;
	Shader(const char* vertexPath,const char* fragmentPath);
	~Shader();
	void Use();
	void SetBool(const std::string& name, bool value); 
	void SetInt(const std::string& name, int value);
	void SetFloat(const std::string& name, float value);
private:
	void CheckComplieErrors(unsigned int shader, std::string type);

};