#include <string>
#include <iostream>

class Logger
{
public:
    // ƒл€ того, чтобы обратитьс€ к единственному экземпл€ру класса используетс€ специальна€ статическа€ Get-функци€
    static Logger& GetInstance()
    {
        static Logger instance; // instance-экземпл€р
        return instance;
    }

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void Log(std::string message)
    {
        std::cout << "LOG: " << message << std::endl;
    }
private:
    static inline unsigned int counter = 0;
    Logger()
    {
        counter++;
        std::cout << "Ёкземпл€р Ћоггер класса был создан!" << counter << std::endl;
    }

    ~Logger()
    {
        counter--;
        std::cout << "Ёкземпл€р Ћоггер класса был разобран :(" << counter << std::endl;
    }
};