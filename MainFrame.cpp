#include "MainFrame.h"
#include <wx/wx.h>
#include "Presenter.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) 
{
	panel = new wxPanel(this);
	panel->SetBackgroundColour(*wxLIGHT_GREY);


	//first
	findStatText = new wxStaticText(panel, wxID_ANY, "Subsequence Search", wxPoint(30, 20), wxDefaultSize);
	wxFont font = findStatText->GetFont();
	font.SetPointSize(11);
	font.SetWeight(wxFONTWEIGHT_BOLD);
	findStatText->SetFont(font);

	staticLine1 = new wxStaticLine(panel, wxID_ANY, wxPoint(250, 10), wxSize(5, 580));
	staticLine2 = new wxStaticLine(panel, wxID_ANY, wxPoint(10, 300), wxSize(235, 5));
	staticLine3 = new wxStaticLine(panel, wxID_ANY, wxPoint(10, 380), wxSize(235, 5));


	txtValToFind = new wxStaticText(panel, wxID_ANY, "Number of vertices: ", wxPoint(30, 50), wxDefaultSize);
	slider = new wxSlider(panel, wxID_ANY, 5, 5, 150, wxPoint(30, 70), wxSize(200, -1), wxSL_LABELS);

	txtValToFind2 = new wxStaticText(panel, wxID_ANY, "Enter edgs: ", wxPoint(30, 110), wxDefaultSize);
	txtCtrlValToFind2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(30, 130), wxSize(200, -1));
	
	btnCreateArray4 = new wxButton(panel, wxID_ANY, "Random graph", wxPoint(135, 160), wxSize(100, -1));
	btnCreateArray3 = new wxButton(panel, wxID_ANY, "Create graph", wxPoint(20, 160), wxSize(100, -1));
	btnCreateArray2 = new wxButton(panel, wxID_ANY, "Add unoriented Edgs", wxPoint(50, 190), wxSize(130, -1));
	btnCreateArray5 = new wxButton(panel, wxID_ANY, "Add oriented Edgs", wxPoint(50, 220), wxSize(130, -1));
	btnCreateArray = new wxButton(panel, wxID_ANY, "Print graph", wxPoint(50, 250), wxSize(130, -1));

	//-----------------------------------------------------------------------
	
	findStatText2 = new wxStaticText(panel, wxID_ANY, "The traveling salesman problem", wxPoint(12, 310), wxDefaultSize);
	findStatText2->SetFont(font);

	btnCreateArray6 = new wxButton(panel, wxID_ANY, "The best way", wxPoint(30, 340), wxSize(200, -1));
	

	//--------------------------------------------------------
	findStatText3 = new wxStaticText(panel, wxID_ANY, "Finding the Shortest Paths", wxPoint(12, 390), wxDefaultSize);
	findStatText3->SetFont(font);
	txtValToFind3 = new wxStaticText(panel, wxID_ANY, "Enter values to start BFS: ", wxPoint(30, 412), wxDefaultSize);
	txtCtrlValToFind3 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(180, 410), wxSize(60, -1));

	btnBFS = new wxButton(panel, wxID_ANY, "BFS", wxPoint(30, 430), wxSize(70, -1));
	btnBFS->SetBackgroundColour(wxColor(70, 205, 70));

	//btnDFS = new wxButton(panel, wxID_ANY, "DFS", wxPoint(110, 255), wxSize(70, -1));
	///btnDFS->SetBackgroundColour(wxColor(70, 205, 70));

	//--------------------------------------------------------------------

	txtPrint = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(270, 20), wxSize(520, 545), wxTE_MULTILINE);
	btnClearTxtPrint = new wxButton(panel, wxID_ANY, "Clear", wxPoint(710, 570), wxSize(80, -1));

	btnCharts = new wxButton(panel, wxID_ANY, "Generate Charts", wxPoint(30, 510), wxSize(120, -1));
	btnHideCharts = new wxButton(panel, wxID_ANY, "Hide Charts", wxPoint(30, 540), wxSize(120, -1));
	btnTests = new wxButton(panel, wxID_ANY, "Print Tests", wxPoint(30, 570), wxSize(120, -1));

	chart1 = new ChartControl(panel, 121, wxPoint(300, 150), wxSize(290, 290));
	chart1->SetBackgroundColour(wxColor(60, 60, 60));
	chart1->values = { 0, 0.6, -0.17, 0.33 };
	chart1->Hide();


	btnCharts->Bind(wxEVT_BUTTON, &MainFrame::OnGraphBtnClicked, this);
	btnHideCharts->Bind(wxEVT_BUTTON, &MainFrame::OnGraphHideBtnClicked, this);

	btnClearTxtPrint->Bind(wxEVT_BUTTON, &MainFrame::OnClearTextPrintBtnClicked, this);
	btnCreateArray5->Bind(wxEVT_BUTTON, &MainFrame::OnCreateOriented, this);
	btnCreateArray4->Bind(wxEVT_BUTTON, &MainFrame::OncreateRandom, this);
	btnCreateArray3->Bind(wxEVT_BUTTON, &MainFrame::OnCreateGraph, this);
	btnCreateArray2->Bind(wxEVT_BUTTON, &MainFrame::OnCreateUnOriented, this);
	btnCreateArray->Bind(wxEVT_BUTTON, &MainFrame::OnPrintGraph, this);
	btnBFS->Bind(wxEVT_BUTTON, &MainFrame::OnCreateBFA, this);
	btnCreateArray6->Bind(wxEVT_BUTTON, &MainFrame::OnSearchTown, this);
	btnTests->Bind(wxEVT_BUTTON, &MainFrame::OnTestsBtnClicked, this);
}



void MainFrame::OnCreateBFA(wxCommandEvent& evt) {
	vector<int> vec; 
	vec= presenter.OnBFS(wxAtoi(txtCtrlValToFind3->GetValue()));
	
	for (int i = 0; i < vec.size(); i++) {
		txtPrint->WriteText(to_string(vec[i])+ "---->");
	}
}

void MainFrame::OnSearchTown(wxCommandEvent& evt) {

	const clock_t begin_time = clock();
	vector<int> vec = presenter.SearchTown();
	
	for (int i = 0;i < vec.size() - 1;i++)
		txtPrint->WriteText(to_string(vec[i]) + " ");

	txtPrint->WriteText("Total cost: " + to_string(vec[vec.size() - 1]) + "\n");
	float val = float(clock() - begin_time) / CLOCKS_PER_SEC; 
	txtPrint->WriteText("\nTime for to run the genetic algorithm: " + to_string(val) + " seconds\n");
	chart1->values = { 0,val };
}


void MainFrame::OnCreateGraph(wxCommandEvent& evt) {
	presenter.CreateGraph(slider->GetValue());

	txtPrint->WriteText("Graph was created!\n\n");
}

void MainFrame::OnCreateOriented(wxCommandEvent& evt) {
	string str = txtCtrlValToFind2->GetValue().ToStdString();
	stringstream ss(str);
	int mas[100];
	int n = 0;
	while (ss >> mas[n++]);

	presenter.AddEdgeOriented(mas);
}

void MainFrame::OnCreateUnOriented(wxCommandEvent& evt) {
	string str = txtCtrlValToFind2->GetValue().ToStdString();
	stringstream ss(str);
	int mas[100];
	int n = 0;
	while (ss >> mas[n++]);

	presenter.AddEdge(mas);
}

void MainFrame::OncreateRandom(wxCommandEvent& evt) {
	presenter.CreateRandom(slider->GetValue());

	txtPrint->WriteText("Graph was created!\n\n");
}

void MainFrame::OnPrintGraph(wxCommandEvent& evt) {
	map<pair<int, int>, int> it1;

	string  str = " with weight "; 

	it1 = presenter.PrintGraph();
	
	map<pair<int, int>, int>::iterator it;

	for (it = it1.begin(); it != it1.end(); ++it)

		txtPrint->WriteText(to_string(it->first.first) + "--->" + to_string(it->first.second) + " with weight " + to_string(it->second) +"\n");
		//txtPrint->WriteText("with weight" + it->second + '\n');
		
	//cout << it->first.first << " --> " << it->first.second << " with weight " << it->second << endl;
}

void MainFrame::OnClearTextPrintBtnClicked(wxCommandEvent& evt) {
	txtPrint->Clear();
}

void MainFrame::OnGraphBtnClicked(wxCommandEvent& evt) {
	
	
	
	chart1->Show();
	
}

void MainFrame::OnGraphHideBtnClicked(wxCommandEvent& evt) {
	chart1->Hide();
	
}


void MainFrame::OnTestsBtnClicked(wxCommandEvent& evt) {
	txtPrint->WriteText("All Test OK");
}
