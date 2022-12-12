#pragma once
#include <wx/wx.h>
#include <wx/statline.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <time.h>

#include "Presenter.h"
#include "Chartcontrol.h"


class MainFrame : public wxFrame {
public:
	MainFrame(const wxString& title);
	wxTextCtrl* txtCtrlValToFind, * txtCtrlValToFind2, * txtCtrlValToFind3, * txtPrint;

private:
	wxStaticText* findStatText, *findStatText2, * findStatText3;
	wxPanel* panel;
	wxStaticLine* staticLine1, * staticLine2, * staticLine3, * staticLine4;
	wxStaticText* txtValToFind,*txtValToFind2, *txtValToFind3;
	wxSlider* slider;
	wxButton* btnCreateArray, * btnCreateArray2, * btnCreateArray4 ,*btnCreateArray5, *btnCreateArray3, * btnCreateArray6, *btnBFS, *btnDFS, *btnClearTxtPrint, * btnCharts, *btnHideCharts, *btnTests;
	ChartControl* chart1;
	Presenter presenter;
	
	void OnCreateBFA(wxCommandEvent& evt);
	void OnTestsBtnClicked(wxCommandEvent& evt);
	void OnSearchTown(wxCommandEvent& evt);
	void OncreateRandom(wxCommandEvent& evt);
	void OnCreateGraph(wxCommandEvent& evt);
	void OnCreateUnOriented(wxCommandEvent& evt);
	void OnCreateOriented(wxCommandEvent& evt);
	void OnPrintGraph(wxCommandEvent& evt);
	void OnClearTextPrintBtnClicked(wxCommandEvent& evt);
	void OnGraphBtnClicked(wxCommandEvent& evt);
	void OnGraphHideBtnClicked(wxCommandEvent& evt);
};