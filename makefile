# final_project: Button.o CheckedOption.o CheckList.o ComboBox.o Component.o HandleIO.o Label.o List.o ListenerCancel.o ListenerMinus.o ListenerOk.o ListenerPlus.o main.o Panel.o MessageBoxComp.o NumericBox.o Option.o RadioBox.o SelectedOption.o TextBox.o ListenerShowList.o
# 	g++ Button.o CheckedOption.o CheckList.o ComboBox.o Component.o HandleIO.o Label.o List.o ListenerCancel.o ListenerMinus.o ListenerOk.o ListenerPlus.o main.o Panel.o MessageBoxComp.o NumericBox.o Option.o RadioBox.o SelectedOption.o TextBox.o ListenerShowList.o -o final_project

final_project: Button.o CheckedOption.o CheckList.o ComboBox.o Component.o HandleIO.o Label.o List.o  ListenerMinus.o ListenerPlus.o main.o NumericBox.o Option.o Panel.o RadioBox.o SelectedOption.o TextBox.o ListenerShowList.o
	g++ Button.o CheckedOption.o CheckList.o ComboBox.o Component.o HandleIO.o Label.o List.o  ListenerMinus.o ListenerPlus.o main.o NumericBox.o Option.o Panel.o RadioBox.o SelectedOption.o TextBox.o ListenerShowList.o -o final_project


Button.o: Button.cpp
	g++ -c Button.cpp

CheckedOption.o: CheckedOption.cpp
	g++ -c CheckedOption.cpp

CheckList.o: CheckList.cpp
	g++ -c CheckList.cpp

ComboBox.o: ComboBox.cpp
	g++ -c ComboBox.cpp

Component.o: Component.cpp
	g++ -c Component.cpp

HandleIO.o: HandleIO.cpp
	g++ -c HandleIO.cpp

Label.o: Label.cpp
	g++ -c Label.cpp

List.o: List.cpp
	g++ -c List.cpp

# ListenerCancel.o: ListenerCancel.cpp
# 	g++ -c ListenerCancel.cpp

ListenerMinus.o: ListenerMinus.cpp
	g++ -c ListenerMinus.cpp

# ListenerOk.o: ListenerOk.cpp
# 	g++ -c ListenerOk.cpp

ListenerPlus.o: ListenerPlus.cpp
	g++ -c ListenerPlus.cpp

main.o: main.cpp
	g++ -c main.cpp

Panel.o: Panel.cpp
	g++ -c Panel.cpp	

# MessageBoxComp.o: MessageBoxComp.cpp
# 	g++ -c MessageBoxComp.cpp

NumericBox.o: NumericBox.cpp
	g++ -c NumericBox.cpp

Option.o: Option.cpp
	g++ -c Option.cpp


RadioBox.o: RadioBox.cpp
	g++ -c RadioBox.cpp

SelectedOption.o: SelectedOption.cpp
	g++ -c SelectedOption.cpp

TextBox.o: TextBox.cpp
	g++ -c TextBox.cpp

ListenerShowList.o: ListenerShowList.cpp
	g++ -c ListenerShowList.cpp

clean:
	rm *.o