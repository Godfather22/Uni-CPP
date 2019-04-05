#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include <string>
unsigned counter = 0;
struct Option
{
	Option(const std::string&, const double);
	double val = 0;
	std::string text;
};
Option::Option(const std::string& txt, const double val) : text(txt), val(val)
{
}
class Question
{
public:
	Question(const std::string&);
	void AddOption(const std::string&, const double);
	void AskQuestion();
	int AnswerQuestion();
private:
	std::string m_Question;
	std::vector<Option>m_Answers;
	double m_Score = 0;
};
void Question::AddOption(const std::string& rhs, const double val)
{
	Option opt(rhs, val);
	m_Answers.push_back(opt);
}
Question::Question(const::std::string& task) : m_Question(task)
{
}
int Randomize(const int i)
{
	return std::rand() % i;
}
void Question::AskQuestion()
{
	std::cout << m_Question << "\n\n";
	std::srand(unsigned(std::time(0)));
	for (unsigned i = 0; i < m_Answers.size(); ++i)
		std::swap(m_Answers[Randomize(m_Answers.size())], m_Answers[Randomize(m_Answers.size())]);
	for (unsigned i = 0; i < m_Answers.size(); ++i)
	{
		char ind = i + 65;
		std::cout << ind << ' ' << m_Answers[i].text << '\n';
	}
}

int Question::AnswerQuestion()
{
	char tmp = 'v';
	unsigned tmpToInt;
	std::cin >> tmp;
	tmpToInt = tmp;
	do
	{
		if (tmpToInt < 97)
			tmpToInt -= 65;
		else
			tmpToInt -= 97;
		m_Score += m_Answers[tmpToInt].val;
		std::cin >> tmp;
		tmpToInt = tmp;
	} while (tmp != 's' && tmp != 'S');
	std::cout << "Резултат: " << m_Score << "\nВерен отговор(и): ";
	for (unsigned i = 0; i < m_Answers.size(); ++i)
		if (m_Answers[i].val > 0)
			std::cout << char(i + 65) << ' ';
	std::cout << "\nВъведи някой символ...\n";
	if (m_Score > 0)
		counter++;
	return m_Score;
}
int main()
{
	setlocale(LC_ALL, "Bulgarian");

	std::cout << "Тест 2 по КАРХ.\nИзготвен от Марто, Даката, Икбал и М.\nПреведен от shlokavica на български от Ицо.\n";
	std::cout << "За да отговорите на някой въпрос, въведете буквата (буквите) и когато сте готови въведете 's'.\n";
	std::cout << "Съобразете се как работи std::cin.\nАко желаете симулация без повторни опити, натиснете r.\nАко желаете въпросите, които объркате да се запазват, натиснете произволен бутон.\n";
	char useless;
	std::cin >> useless;
	bool flag = (useless == 'r' ? 1 : 0);
	system("CLS");
	std::vector<Question> exam;
	std::srand(unsigned(std::time(0)));

	Question q1("Каква е целта на използването на CMOVZ?");
	q1.AddOption("Редуциране на условните преходи", 1);
	q1.AddOption("Спестяване на памет", -1);
	q1.AddOption("Избягване на логическа грешка", -1);
	q1.AddOption("Предотвратяване на мехури в конвейера", -1);
	exam.push_back(q1);

	Question q2("Кои от изброените абревиатури са имена на шини?");
	q2.AddOption("USB, CAN, I2C", 1);
	q2.AddOption("LPT, PWM, I2C", -1);
	q2.AddOption("Com-port, PCA, PWM", -1);
	q2.AddOption("PCA, ISA, RJ11", -1);
	exam.push_back(q2);

	Question q3("Кой от посочените компоненти осъществява връзка с вътрешна шина?");
	q3.AddOption("USB", -1);
	q3.AddOption("LPT", -1);
	q3.AddOption("Com-port", -1);
	q3.AddOption("PCI", 0.5);
	q3.AddOption("ISA", 0.5);
	q3.AddOption("Ethernet", -1);
	exam.push_back(q3);

	Question q4("Кой от посочените компоненти осъществява връзка с външна шина?");
	q4.AddOption("USB", 0.25);
	q4.AddOption("LPT", 0.25);
	q4.AddOption("Com-port", 0.25);
	q4.AddOption("PCI", -1);
	q4.AddOption("ISA", -1);
	q4.AddOption("Ethernet", 0.25);
	exam.push_back(q4);

	Question q5("Как се случват във времето REQ и GNT?");
	q5.AddOption("Получава се GNT, а след това REQ", -5);
	q5.AddOption("Получава се REQ, след което GNT", 1);
	q5.AddOption("След получаване на REQ, веднага се генерира GNT", -1);
	q5.AddOption("След получаване на GNT, веднага се генерира REQ", -5);
	exam.push_back(q5);

	Question q6("Между T3 и T4 кой установява сигналите за данни на шината за първата част на картинката?\nIMG not found");
	q6.AddOption("Master", -1);
	q6.AddOption("Slave", 1);
	exam.push_back(q6);

	Question q7("Между T3 и T4 кой установява сигналите за данни на шината за втората част на картинката?\nIMG not found");
	q7.AddOption("Master", 1);
	q7.AddOption("Slave", -1);
	exam.push_back(q7);

	Question q8("Защо има по една стрелка във всяка посока?");
	q8.AddOption("Защото са диференциални двойки", -1);
	q8.AddOption("Защото не стига честотната линия", -1);
	q8.AddOption("За постигане на по-високи скорости", -1);
	q8.AddOption("Всички са верни", 1);
	exam.push_back(q8);

	Question q9("Какво означава CRC?");
	q9.AddOption("Cyclic Redundancy Check", 1);
	q9.AddOption("Complete Register Content", -1);
	q9.AddOption("Connection Regulating Chip", -1);
	q9.AddOption("Create Read Clear", -1);
	exam.push_back(q9);

	Question q10("Коя шина има посока от uC HOST към Ethernet?\nImg not found");
	q10.AddOption("TXD", 1);
	q10.AddOption("RXD", -1);
	exam.push_back(q10);

	Question q11("Коя шина има посока от Ethernet към ucHost?\nImg not found");
	q11.AddOption("TXD", -1);
	q11.AddOption("RXD", 1);
	exam.push_back(q11);

	Question q12("Какво е DMA?");
	q12.AddOption("Direct Memory Access", 1);
	q12.AddOption("Digital Machine Accumulator", -1);
	q12.AddOption("Digital Memory Access", -1);
	q12.AddOption("Detector of Masked Attacks", -1);
	exam.push_back(q12);

	Question q13("Колко проводна е USB3 шината?");
	q13.AddOption("9", 1);
	q13.AddOption("3", -1);
	q13.AddOption("6", -1);
	q13.AddOption("1", -1);
	exam.push_back(q13);

	Question q14("Колко проводна е USB2 шината?");
	q14.AddOption("4", 1);
	q14.AddOption("2", -1);
	q14.AddOption("8", -1);
	q14.AddOption("1", -1);
	exam.push_back(q14);

	Question q15("Защо D+ и D- са усукани?");
	q15.AddOption("За повишаване на скоростта", -1);
	q15.AddOption("За по-голяма здравина", -1);
	q15.AddOption("За по-добра гъвкавост на кабела", -1);
	q15.AddOption("За шумоустойчивост", 1);
	exam.push_back(q15);

	Question q16("Какво е SOF?");
	q16.AddOption("Start of Frame", 1);
	q16.AddOption("Superior orbital fissure", -100);
	q16.AddOption("Sequence of Files", -1);
	q16.AddOption("Single Offset Flag", -1);
	exam.push_back(q16);

	Question q17("Кой фрейм е за четене?");
	q17.AddOption("Първи", 1);
	q17.AddOption("Втори", -1);
	q17.AddOption("Трети", -1);
	q17.AddOption("Четвърти", -1);
	exam.push_back(q17);

	Question q18("Кой фрейм е за писане?");
	q18.AddOption("Първи", -1);
	q18.AddOption("Втори", -1);
	q18.AddOption("Трети", 1);
	q18.AddOption("Четвърти", -1);
	exam.push_back(q18);

	Question q19("За какво служат резисторите?");
	q19.AddOption("За създаване на електрическо съпротивление", 1);
	q19.AddOption("За по-бърза връзка с паметта", -1);
	q19.AddOption("За защита от удари", -1);
	q19.AddOption("За ускоряване на връзката между шините и процесора", -1);
	exam.push_back(q19);

	Question q20("Какво е предназначението на predicate?");
	q20.AddOption("Да опише даден процес", 1);
	q20.AddOption("Да оптимизира операция", -1);
	q20.AddOption("Да намали латентността", -1);
	q20.AddOption("Да ускори работата с процесора", -1);
	exam.push_back(q20);

	Question q21("Има срязана картинка и Русалчо пита кое е първо");
	q21.AddOption("Read", 1);
	q21.AddOption("Write", -1);
	q21.AddOption("Idle", -1);
	exam.push_back(q21);

	Question q22("Има срязана картинка и Русалчо пита кое е по средата");
	q22.AddOption("Read", -1);
	q22.AddOption("Write", -1);
	q22.AddOption("Idle", 1);
	exam.push_back(q22);

	Question q23("Има срязана картинка и Русалчо пита кое е накрая");
	q23.AddOption("Read", -1);
	q23.AddOption("Write", 1);
	q23.AddOption("Idle", -1);
	exam.push_back(q23);

	unsigned questionsCount = exam.size();
	for (unsigned i = 0; i < questionsCount; ++i)
		std::swap(exam[Randomize(exam.size())], exam[Randomize(exam.size())]);
	for (unsigned i = 0; i < exam.size(); ++i)
	{
		if (i == questionsCount)
		{
			std::cout << "Секция със сгрешени въпроси\nнатиснете някой бутон\n";
			std::cin >> useless;
			system("CLS");
		}
		std::cout << 1 + i << '/' << exam.size() << '\n';
		exam[i].AskQuestion();
		if (exam[i].AnswerQuestion() != 1 && !flag)
			exam.push_back(exam[i]);
		std::cin >> useless;
		system("CLS");
	}
	std::cout << "Congratulations for reaching the end!\nYour score is: " << counter << '/' << exam.size();
	std::cin >> useless;
	return 0;
}
