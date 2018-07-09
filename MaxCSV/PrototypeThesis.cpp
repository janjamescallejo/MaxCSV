// MaxCSV.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <objbase.h>
#include <windows.h>
#include "Combined.h"
#include "Database.h"

using namespace std;
int samplenum;
double joymax = 0;
double fearmax = 0;
double disgustmax = 0;
double sadnessmax = 0;
double angermax = 0;
double surprisemax = 0;
double contemptmax = 0;
double timemax = 0;
double timestamps[35];
double maxvalues[34][7];
double empathValues[34][5];
double combinedvalues[34][11];
double sout;
double nsucsum = 0;
double nfaisum = 0;
class line {
public:
	string TimeStamp;
	string faceID;
	string interocularDistance;
	string glasses;
	string age;
	string ethnicity;
	string gender;
	string dominant;
	string pitch;
	string yaw;
	string roll;
	string joy;
	string fear;
	string disgust;
	string sadness;
	string anger;
	string surprise;
	string contempt;
	string valence;
	string engagement;
	string smile;
	string innerBrowRaise;
	string browRaise;
	string browFurrow;
	string noseWrinkle;
	string upperLipRaise;
	string lipCornerDepressor;
	string chinRaise;
	string lipPucker;
	string lipPress;
	string lipSuck;
	string mouthOpen;
	string smirk;
	string eyeClosure;
	string attention;
	string eyeWiden;
	string cheekRaise;
	string lidTighten;
	string dimpler;
	string lipStretch;
	string jawDrop;
	string relaxed;
	string smiley;
	string laughing;
	string kissing;
	string disappointed;
	string rage;
	string smirk1;
	string wink;
	string stuckOutTongueWinkingEye;
	string stuckOutTongue;
	string flushed;
	string scream;
	void setvalues(string i1, string i2, string i3, string i4, string i5, string i6, string i7, string i8, string i9, string i10, string i11, string i12, string i13, string i14, string i15, string i16, string i17, string i18, string i19, string i20, string i21, string i22, string i23, string i24, string i25, string i26, string i27, string i28, string i29, string i30, string i31, string i32, string i33, string i34, string i35, string i36, string i37, string i38, string i39, string i40, string i41, string i42, string i43, string i44, string i45, string i46, string i47, string i48, string i49, string i50, string i51, string i52, string i53);
};
void line::setvalues(string i1, string i2, string i3, string i4, string i5, string i6, string i7, string i8, string i9, string i10, string i11, string i12, string i13, string i14, string i15, string i16, string i17, string i18, string i19, string i20, string i21, string i22, string i23, string i24, string i25, string i26, string i27, string i28, string i29, string i30, string i31, string i32, string i33, string i34, string i35, string i36, string i37, string i38, string i39, string i40, string i41, string i42, string i43, string i44, string i45, string i46, string i47, string i48, string i49, string i50, string i51, string i52, string i53)
{
	TimeStamp = i1;
	faceID = i2;
	interocularDistance = i3;
	glasses = i4;
	age = i5;
	ethnicity = i6;
	gender = i7;
	dominant = i8;
	pitch = i9;
	yaw = i10;
	roll = i11;
	joy = i12;
	fear = i13;
	disgust = i14;
	sadness = i15;
	anger = i16;
	surprise = i17;
	contempt = i18;
	valence = i19;
	engagement = i20;
	smile = i21;
	innerBrowRaise = i22;
	browRaise = i23;
	browFurrow = i24;
	noseWrinkle = i25;
	upperLipRaise = i26;
	lipCornerDepressor = i27;
	chinRaise = i28;
	lipPucker = i29;
	lipPress = i30;
	lipSuck = i31;
	mouthOpen = i32;
	smirk = i33;
	eyeClosure = i34;
	attention = i35;
	eyeWiden = i36;
	cheekRaise = i37;
	lidTighten = i38;
	dimpler = i39;
	lipStretch = i40;
	jawDrop = i41;
	relaxed = i42;
	smiley = i43;
	laughing = i44;
	kissing = i45;
	disappointed = i46;
	rage = i47;
	smirk1 = i48;
	wink = i49;
	stuckOutTongueWinkingEye = i50;
	stuckOutTongue = i51;
	flushed = i52;
	scream = i53;
}
void reveal(line l)
{
	double djoy, dfear, ddisgust, dsadness, danger, dsurprise, dcontempt, dtime;
	try {
		djoy = stod(l.joy);
		dfear = stod(l.fear);
		ddisgust = stod(l.disgust);
		dsadness = stod(l.sadness);
		danger = stod(l.anger);
		dsurprise = stod(l.surprise);
		dcontempt = stod(l.contempt);
		dtime = stod(l.TimeStamp);
	}
	catch (exception e)
	{
		djoy = 0;
		dfear = 0;
		ddisgust = 0;
		dsadness = 0;
		danger = 0;
		dsurprise = 0;
		dcontempt = 0;
		dtime = 0;
	}
	if (djoy>joymax)
		joymax = djoy;

	if (dfear>fearmax)
		fearmax = dfear;

	if (ddisgust>disgustmax)
		disgustmax = ddisgust;

	if (dsadness>sadnessmax)
		sadnessmax = dsadness;

	if (danger>angermax)
		angermax = danger;

	if (dsurprise>surprisemax)
		surprisemax = dsurprise;

	if (dcontempt>contemptmax)
		contemptmax = dcontempt;
	if (dtime > timemax)
		timemax = dtime;
}
vector<line> vic;
vector<line> vic1;
vector<line> vic2;
vector<line> vic3;
vector<line> vic4;
vector<line> vic5;
vector<line> vic6;
vector<line> vic7;
vector<line> vic8;
vector<line> vic9;
vector<line> vic10;
vector<line> vic11;
vector<line> vic12;
vector<line> vic13;
vector<line> vic14;
vector<line> vic15;
vector<line> vic16;
vector<line> vic17;
vector<line> vic18;
vector<line> vic19;
vector<line> vic20;
vector<line> vic21;
vector<line> vic22;
vector<line> vic23;
vector<line> vic24;
vector<line> vic25;
vector<line> vic26;
vector<line> vic27;
vector<line> vic28;
vector<line> vic29;
vector<line> vic30;
vector<line> vic31;
vector<line> vic32;
vector<line> vic33;
vector<line> vic34;
database d;
 void split(line l)
 {
	 double time;
	 try {
		 time = stod(l.TimeStamp);
	 }
	 catch (exception e)
	 {
		 time = 0;
	 }

	 if (time >= timestamps[0] )
	 {
		 if(time < timestamps[1])
		 vic1.push_back(l);
	}
	 if (time >= timestamps[1])
	 {
		 if (time < timestamps[2])
			 vic2.push_back(l);
	 }
	 if (time >= timestamps[2])
	 {
		 if (time < timestamps[3])
			 vic3.push_back(l);
	 }
	 if (time >= timestamps[3])
	 {
		 if (time < timestamps[4])
			 vic4.push_back(l);
	 }
	 if (time >= timestamps[4])
	 {
		 if (time < timestamps[5])
			 vic5.push_back(l);
	 }
	 if (time >= timestamps[5])
	 {
		 if (time < timestamps[6])
			 vic6.push_back(l);
	 }
	 if (time >= timestamps[6])
	 {
		 if (time < timestamps[7])
			 vic7.push_back(l);
	 }
	 if (time >= timestamps[7])
	 {
		 if (time < timestamps[8])
			 vic8.push_back(l);
	 }
	 if (time >= timestamps[8])
	 {
		 if (time < timestamps[9])
			 vic9.push_back(l);
	 }
	 if (time >= timestamps[9])
	 {
		 if (time < timestamps[10])
			 vic10.push_back(l);
	 }
	 if (time >= timestamps[10])
	 {
		 if (time < timestamps[11])
			 vic11.push_back(l);
	 }
	 if (time >= timestamps[11])
	 {
		 if (time < timestamps[12])
			 vic12.push_back(l);
	 }
	 if (time >= timestamps[12])
	 {
		 if (time < timestamps[13])
			 vic13.push_back(l);
	 }
	 if (time >= timestamps[13])
	 {
		 if (time < timestamps[14])
			 vic14.push_back(l);
	 }
	 if (time >= timestamps[14])
	 {
		 if (time < timestamps[15])
			 vic15.push_back(l);
	 }
	 if (time >= timestamps[15])
	 {
		 if (time < timestamps[16])
			 vic16.push_back(l);
	 }
	 if (time >= timestamps[16])
	 {
		 if (time < timestamps[17])
			 vic17.push_back(l);
	 }
	 if (time >= timestamps[17])
	 {
		 if (time < timestamps[18])
			 vic18.push_back(l);
	 }
	 if (time >= timestamps[18])
	 {
		 if (time < timestamps[19])
			 vic19.push_back(l);
	 }
	 if (time >= timestamps[19])
	 {
		 if (time < timestamps[20])
			 vic20.push_back(l);
	 }
	 if (time >= timestamps[20])
	 {
		 if (time < timestamps[21])
			 vic21.push_back(l);
	 }
	 if (time >= timestamps[21])
	 {
		 if (time < timestamps[22])
			 vic22.push_back(l);
	 }
	 if (time >= timestamps[22])
	 {
		 if (time < timestamps[23])
			 vic23.push_back(l);
	 }
	 if (time >= timestamps[23])
	 {
		 if (time < timestamps[24])
			 vic24.push_back(l);
	 }
	 if (time >= timestamps[24])
	 {
		 if (time < timestamps[25])
			 vic25.push_back(l);
	 }
	 if (time >= timestamps[25])
	 {
		 if (time < timestamps[26])
			 vic26.push_back(l);
	 }
	 if (time >= timestamps[26])
	 {
		 if (time < timestamps[27])
			 vic27.push_back(l);
	 }
	 if (time >= timestamps[27])
	 {
		 if (time < timestamps[28])
			 vic28.push_back(l);
	 }
	 if (time >= timestamps[28])
	 {
		 if (time < timestamps[29])
			 vic29.push_back(l);
	 }
	 if (time >= timestamps[29])
	 {
		 if (time < timestamps[30])
			 vic30.push_back(l);
	 }
	 if (time >= timestamps[30])
	 {
		 if (time < timestamps[31])
			 vic31.push_back(l);
	 }
	 if (time >= timestamps[31])
	 {
		 if (time < timestamps[32])
			 vic32.push_back(l);
	 }
	 if (time >= timestamps[32])
	 {
		 if (time < timestamps[33])
			 vic33.push_back(l);
	 }
	 if (time >= timestamps[33])
	 {
		 if (time < timestamps[34])
			 vic34.push_back(l);
	 }
 }
 void displaymax(int i)
 {
	 cout << timemax << endl;
 maxvalues[i - 1][0] = joymax;
 maxvalues[i - 1][1] = fearmax;
 maxvalues[i - 1][2] = disgustmax;
 maxvalues[i - 1][3] = sadnessmax;
 maxvalues[i - 1][4] = angermax;
 maxvalues[i - 1][5] = surprisemax;
 maxvalues[i - 1][6] = contemptmax;
 joymax=0;
 fearmax=0;
 disgustmax=0;
 sadnessmax=0;
 angermax=0;
 surprisemax=0;
 contemptmax=0;
 timemax = 0;
 }
 void convertDouble(string input, int query, int number)
 {
	 empathValues[query][number] = stod(input);
 }
 void empathstring(string emp, int query)
 {

	 emp.erase(emp.begin());
	 string delimiter = ",";
	 int i = 0;
	 size_t pos = 0;
	 size_t pos2 = 0;
	 string token;
	 while ((pos = emp.find(delimiter)) != std::string::npos) {
		 token = emp.substr(0, pos);
		 string delimiter2 = ":";
		 pos2 = token.find(delimiter2);
		 token.erase(0, pos2 + delimiter2.length());
		 convertDouble(token, query, i);
		 cout << token << endl;

		 emp.erase(0, pos + delimiter.length());
		 i++;
	 }

 }
 void combine()
 {
	 for (int i = 0; i < 34; i++)
	 {
		 for (int j = 0; j < 11; j++)
		 {
			 if (j < 7)
				 combinedvalues[i][j] = maxvalues[i][j];
			 else 
			 {
				 if (j == 7)
					 combinedvalues[i][j] = empathValues[i][1];
				 if (j == 8)
					 combinedvalues[i][j] = empathValues[i][2];
				 if (j == 9)
					 combinedvalues[i][j] = empathValues[i][3];
				 if (j == 10)
					 combinedvalues[i][j] = empathValues[i][4];

			 }
		}
	 }
 }
 string J48decision(int i, double joy, double fear, double disgust, double sadness, double anger, double surprise, double contempt, double calm, double angered, double joyful, double sorrow)
 {
	 string decision;
	 if (sadness <= 0.0724)
	 {
		 if (disgust <= 0.7575)
		 {
			 if (joy <= 99.8443)
			 {
				 if (contempt <= 0.1928)
				 {
					 if (joyful <= 0)
					 {
						 if (contempt <= 0.0003)
							 decision = "FAIL";
						 else
						 {
							 if (surprise <= 0.2415)
								 decision = "SUCCESS";
							 else
							 {
								 if (sadness <= 0.007)
									 decision = "SUCCESS";
								 else
									 decision = "FAIL";
							 }
						 }
					 }
					 else
						 decision = "FAIL";
				 }
				 else
					 decision = "FAIL";
			 }
			 else
				 decision = "FAIL";
		 }
		 else
		 {
			 if (disgust <= 99.5258)
			 {
				 if (calm <= 30)
				 {
					 if (sadness <= 0.0246)
						 decision = "FAIL";
					 else
					 {
						 if (angered <= 20)
						 {
							 if (disgust <= 77.4014)
							 {
								 if (joyful <= 23)
								 {
									 if (anger <= 0.0152)
									 {
										 if (fear <= 0.0152)
										 {
											 if (sadness <= 0.0334)
											 {
												 if (joy <= 0.0316)
												 {
													 if (sadness <= 0.0268)
														 decision = "SUCCESS";
													 else
													 {
														 if (calm <= 26)
														 {
															 if (joyful <= 6)
																 decision = "SUCCESS";
															 else
																 decision = "FAIL";
														 }
													 }
												 }
												 else
													 decision = "FAIL";
											 }
											 else
												 decision = "FAIL";
										 }
										 else
										 {
											 if (contempt <= 90.1423)
												 decision = "SUCCESS";
											 else
												 decision = "FAIL";
										 }
									 }
									 else
									 {
										 if (fear <= 0.2814)
											 decision = "FAIL";
										 else
										 {
											 if (sorrow <= 9)
												 decision = "FAIL";
											 else
												 decision = "SUCCESS";
										 }
									 }
								 }
								 else
								 {
									 decision = "FAIL";
								 }
							 }
							 else
								 decision = "FAIL";
						 }
						 else
							 decision = "SUCCESS";
					 }
				 }
				 else
				 {
					 if (fear <= 0.0064)
						 decision = "FAIL";
					 else
					 {
						 if (calm <= 43)
						 {
							 if (anger <= 0.0028)
							 {
								 if (anger <= 0.0002)
									 decision = "FAIL";
								 else
								 {
									 if (sadness <= 0.245)
										 decision = "SUCCESS";
									 else
									 {
										 if (joy <= 51.592)
											 decision = "SUCCESS";
										 else
											 decision = "FAIL";
									 }
								 }
							 }
							 else
								 decision = "FAIL";
						 }
						 else
							 decision = "SUCCESS";
					 }
				 }
			 }
			 else
			 {
				 if (angered <= 4)
				 {
					 if (sorrow <= 3)
						 decision = "SUCCESS";
					 else
					 {
						 if (fear <= 0.572)
							 decision = "SUCCESS";
						 else
							 decision = "FAIL";
					 }
				 }
				 else
					 decision = "FAIL";
			 }
		 }
	 }
	 else
	 {
		 if (calm <= 33)
			 decision = "FAIL";
		 else
		 {
			 if (surprise <= 0.2312)
				 decision = "SUCCESS";
			 else
			 {
				 if (joy <= 0.0019)
				 {
					 if (calm <= 41)
						 decision = "FAIL";
					 else
					 {
						 if (anger <= 0.0047)
							 decision = "SUCCESS";
						 else
						 {
							 if (disgust <= 0.4551)
								 decision = "FAIL";
							 else
							 {
								 if (sadness <= 43.7258)
									 decision = "SUCCESS";
								 else
									 decision = "FAIL";
							 }
						 }
					 }
				 }
				 else
				 {
					 if (joy <= 99.5701)
						 decision = "SUCCESS";
					 else
					 {
						 if (contempt <= 0.2655)
							 decision = "FAIL";
						 else
						 {
							 if (sadness <= 9.2052)
							 {
								 if (anger <= 52.2878)
								 {
									 if (sorrow <= 6)
										 decision = "SUCCESS";
									 else
									 {
										 if (sadness <= 1)
											 decision = "FAIL";
										 else
											 decision = "SUCCESS";
									 }
								 }
								 else
									 decision = "FAIL";
							 }
							 else
							 {
								 if (sorrow <= 2)
									 decision = "FAIL";
								 else
									 decision = "SUCCESS";
							 }
						 }
					 }
				 }
			 }
		 }
	 }
	 d.insertJ48Result(samplenum, i, decision);
	 return decision;

 }
 string SVMdecision(int i, double joy, double fear, double disgust, double sadness, double anger, double surprise, double contempt, double calm, double angered, double joyful, double sorrow)
 {
	 double bias = 1.0922;
	 double joyweight = 0.0017;
	 double fearweight = -0.6345;
	 double disgustweight = -0.0074;
	 double sadnessweight = 0.4053;
	 double angerweight = -2.5047;
	 double surpriseweight = -0.0067;
	 double contemptweight = 0.0131;
	 double calmweight = -0.0315;
	 double angeredweight = 0.0029;
	 double joyfulweight = 0.0029;
	 double sorrowweight = 0.0187;
	 double judgment = bias + joy * joyweight + fear * fearweight + disgust * disgustweight + sadness * sadnessweight + anger * angerweight + surprise * surpriseweight + contempt * contemptweight + calm * calmweight + angered *angeredweight + joyful * joyfulweight + sorrow * sorrowweight;
	 sout = judgment;
	 if (judgment < 0)
	 {
		 d.insertSVMResult(samplenum, i, judgment, "FAIL");
		 return "FAIL";
	 }
	 else
	 {
		 d.insertSVMResult(samplenum, i, judgment, "SUCCESS");
		 return "SUCCESS";
	 }
 }
 string NBdecision(int i, double joy, double fear, double disgust, double sadness, double anger, double surprise, double contempt, double calm, double angered, double joyful, double sorrow)
 {
	 double input[11];
	 input[0] = joy;
	 input[1] = fear;
	 input[2] = disgust;
	 input[3] = sadness;
	 input[4] = anger;
	 input[5] = surprise;
	 input[6] = contempt;
	 input[7] = calm;
	 input[8] = angered;
	 input[9] = joyful;
	 input[10] = sorrow;
	 double inputMeanSuccess[11];
	 inputMeanSuccess[0] = 3.1249;
	 inputMeanSuccess[1] = 2.1108;
	 inputMeanSuccess[2] = 26.0189;
	 inputMeanSuccess[3] = 3.3424;
	 inputMeanSuccess[4] = 2.5984;
	 inputMeanSuccess[5] = 17.2688;
	 inputMeanSuccess[6] = 14.1097;
	 inputMeanSuccess[7] = 34.6099;
	 inputMeanSuccess[8] = 2.5869;
	 inputMeanSuccess[9] = 6.0399;
	 inputMeanSuccess[10] = 4.9393;
	 double inputMeanFail[11];
	 inputMeanFail[0] = 40.6032;
	 inputMeanFail[1] = 1.0318;
	 inputMeanFail[2] = 17.2982;
	 inputMeanFail[3] = 2.2583;
	 inputMeanFail[4] = 1.0152;
	 inputMeanFail[5] = 12.1138;
	 inputMeanFail[6] = 11.5452;
	 inputMeanFail[7] = 29.8941;
	 inputMeanFail[8] = 3.4818;
	 inputMeanFail[9] = 8.6972;
	 inputMeanFail[10] = 6.1471;
	 double inputVarianceSuccess[11];
	 inputVarianceSuccess[0] = 2257.3426;
	 inputVarianceSuccess[1] = 87.3870;
	 inputVarianceSuccess[2] = 1520.8128;
	 inputVarianceSuccess[3] = 170.9164;
	 inputVarianceSuccess[4] = 84.4579;
	 inputVarianceSuccess[5] = 791.5276;
	 inputVarianceSuccess[6] = 921.1346;
	 inputVarianceSuccess[7] = 148.7497;
	 inputVarianceSuccess[8] = 24.6592;
	 inputVarianceSuccess[9] = 67.9058;
	 inputVarianceSuccess[10] = 45.2512;
	 double inputVarianceFail[11];
	 inputVarianceFail[0] = 2310.6576;
	 inputVarianceFail[1] = 40.7452;
	 inputVarianceFail[2] = 1080.8840;
	 inputVarianceFail[3] = 138.8603;
	 inputVarianceFail[4] = 40.7695;
	 inputVarianceFail[5] = 564.0768;
	 inputVarianceFail[6] = 760.1104;
	 inputVarianceFail[7] = 173.8337;
	 inputVarianceFail[8] = 36.6158;
	 inputVarianceFail[9] = 111.4228;
	 inputVarianceFail[10] = 58.1452;
	 double probableSuccess[11];
	 double probableFail[11];
	 double label[2];
	 for (int i = 0; i < 11; i++)
	 {
		 probableSuccess[i] = 1 / sqrt(2 * 3.14 * inputVarianceSuccess[i]) * exp(-(input[i] - inputMeanSuccess[i])* (input[i] - inputMeanSuccess[i]) / (2 * inputVarianceSuccess[i]));
		 probableFail[i] = 1 / sqrt(2 * 3.14 * inputVarianceFail[i]) * exp(-(input[i] - inputMeanFail[i])* (input[i] - inputMeanFail[i]) / (2 * inputVarianceFail[i]));
	 }
	 for (int i = 0; i < 11; i++)
	 {
		 label[0] = label[0] * probableSuccess[i];
		 label[1] = label[1] * probableFail[i];
	 }
	 if (label[0] > label[1])
	 {
		 d.insertNBResult(samplenum, i, label[0], label[1], "SUCCESS");
		 return "Success";
	 }
	 else
	 {
		 d.insertNBResult(samplenum, i, label[0], label[1], "FAIL");
		 return "Fail";
	 }
 }
 void NNdecision(int i, double joy, double fear, double disgust, double sadness, double anger, double surprise, double contempt, double calm, double angered, double joyful, double sorrow)
 {
	 double sigmoidnode0[7];
	 sigmoidnode0[0] = 0.804680577449594;
	 sigmoidnode0[1] = -4.245697246747405;
	 sigmoidnode0[2] = -1.420063943108316;
	 sigmoidnode0[3] = -1.3330678274087004;
	 sigmoidnode0[4] = -1.4729447579702182;
	 sigmoidnode0[5] = -1.4729447579702182;
	 sigmoidnode0[6] = -2.1117325801889084;
	 double sigmoidnode1[7];
	 sigmoidnode1[0] = -0.8046805774496594;
	 sigmoidnode1[1] = 4.245697246747405;
	 sigmoidnode1[2] = 1.420063943108316;
	 sigmoidnode1[3] = 1.3330678274087004;
	 sigmoidnode1[4] = 1.4729447579702182;
	 sigmoidnode1[5] = -2.5144998825918723;
	 sigmoidnode1[6] = 2.1117325801889084;
	 double sigmoidnode2[12];
	 sigmoidnode2[0] = -12.144811586491553;
	 sigmoidnode2[1] = 1.3418230161045663;
	 sigmoidnode2[2] = -2.5174280670573244;
	 sigmoidnode2[3] = -17.73570185924864;
	 sigmoidnode2[4] = 5.171621053033813;
	 sigmoidnode2[5] = -4.090904271113604;
	 sigmoidnode2[6] = -3.0051003452501015;
	 sigmoidnode2[7] = 5.359864853144869;
	 sigmoidnode2[8] = -3.6885759719044366;
	 sigmoidnode2[9] = -0.8971095781309818;
	 sigmoidnode2[10] = 14.833622100361394;
	 sigmoidnode2[11] = 5.976107030400978;
	 double sigmoidnode3[12];
	 sigmoidnode3[0] = -7.8747154861709285;
	 sigmoidnode3[1] = 2.9134097638333727;
	 sigmoidnode3[2] = 5.465521944978445;
	 sigmoidnode3[3] = -2.841618946565676;
	 sigmoidnode3[4] = -7.9865002230279645;
	 sigmoidnode3[5] = -13.178292762934126;
	 sigmoidnode3[6] = 4.718536985262529;
	 sigmoidnode3[7] = -6.727819449141782;
	 sigmoidnode3[8] = -2.836105232153538;
	 sigmoidnode3[9] = 12.298742081701944;
	 sigmoidnode3[10] = -0.35657213343903366;
	 sigmoidnode3[11] = 9.044701600562144;
	 double sigmoidnode4[12];
	 sigmoidnode4[0] = -3.9544029417899704;
	 sigmoidnode4[1] = -2.8169055075815796;
	 sigmoidnode4[2] = -3.867095415579263;
	 sigmoidnode4[3] = -0.02677732040043623;
	 sigmoidnode4[4] = 4.676718930269602;
	 sigmoidnode4[5] = -8.307041866863253;
	 sigmoidnode4[6] = -12.701541216582623;
	 sigmoidnode4[7] = -1.161960746817769;
	 sigmoidnode4[8] = -9.580602864737989;
	 sigmoidnode4[9] = 0.9571498645435002;
	 sigmoidnode4[10] = 10.839930046794844;
	 sigmoidnode4[11] = 5.619857676102202;
	 double sigmoidnode5[12];
	 sigmoidnode5[0] = -15.393668144694647;
	 sigmoidnode5[1] = 23.817405497852633;
	 sigmoidnode5[2] = 4.21805033173585;
	 sigmoidnode5[3] = -22.66220998116557;
	 sigmoidnode5[4] = 7.254688954537451;
	 sigmoidnode5[5] = -20.129766764454427;
	 sigmoidnode5[6] = -24.51164907430425;
	 sigmoidnode5[7] = 0.8029991100752082;
	 sigmoidnode5[8] = 10.410231865707422;
	 sigmoidnode5[9] = 8.623615926385158;
	 sigmoidnode5[10] = 6.920297824506983;
	 sigmoidnode5[11] = 8.740407353719997;
	 double sigmoidnode6[12];
	 sigmoidnode6[0] = -1.1890181946415472;
	 sigmoidnode6[1] = 4.443743950919829;
	 sigmoidnode6[2] = 2.320071315848898;
	 sigmoidnode6[3] = -4.448267468090674;
	 sigmoidnode6[4] = 5.6377857664839235;
	 sigmoidnode6[5] = -0.333379977092494;
	 sigmoidnode6[6] = -11.254448794852653;
	 sigmoidnode6[7] = 3.7811526540462017;
	 sigmoidnode6[8] = -9.384578541987338;
	 sigmoidnode6[9] = -2.932829576975326;
	 sigmoidnode6[10] = 11.39029162930972;
	 sigmoidnode6[11] = 7.348932793224209;
	 double sigmoidnode7[12];
	 sigmoidnode7[0] = -3.1885103043792893;
	 sigmoidnode7[1] = -9.53881595195595;
	 sigmoidnode7[2] = -3.150999767174384;
	 sigmoidnode7[3] = 8.995129336646286;
	 sigmoidnode7[4] = 4.558545398329673;
	 sigmoidnode7[5] = -0.71983130450572;
	 sigmoidnode7[6] = 9.227853984111233;
	 sigmoidnode7[7] = -2.289832263939641;
	 sigmoidnode7[8] = -0.740989550197029;
	 sigmoidnode7[9] = 11.230612330377557;
	 sigmoidnode7[10] = 2.0857774181381;
	 sigmoidnode7[11] = -2.1023081549918734;
	 double firstcom[6];
	 firstcom[0] = sigmoidnode2[0] + sigmoidnode2[1] * joy + sigmoidnode2[2] * fear + sigmoidnode2[3] * disgust + sigmoidnode2[4] * sadness + sigmoidnode2[5] * anger + sigmoidnode2[6] * surprise + sigmoidnode2[7] * contempt + sigmoidnode2[8] * calm + sigmoidnode2[9] * angered + sigmoidnode2[10] * joyful + sigmoidnode2[11] * sorrow;
	 firstcom[1] = sigmoidnode3[0] + sigmoidnode3[1] * joy + sigmoidnode3[2] * fear + sigmoidnode3[3] * disgust + sigmoidnode3[4] * sadness + sigmoidnode3[5] * anger + sigmoidnode3[6] * surprise + sigmoidnode3[7] * contempt + sigmoidnode3[8] * calm + sigmoidnode3[9] * angered + sigmoidnode3[10] * joyful + sigmoidnode3[11] * sorrow;
	 firstcom[2] = sigmoidnode4[0] + sigmoidnode4[1] * joy + sigmoidnode4[2] * fear + sigmoidnode4[3] * disgust + sigmoidnode4[4] * sadness + sigmoidnode4[5] * anger + sigmoidnode4[6] * surprise + sigmoidnode4[7] * contempt + sigmoidnode4[8] * calm + sigmoidnode4[9] * angered + sigmoidnode4[10] * joyful + sigmoidnode4[11] * sorrow;
	 firstcom[3] = sigmoidnode5[0] + sigmoidnode5[1] * joy + sigmoidnode5[2] * fear + sigmoidnode5[3] * disgust + sigmoidnode5[4] * sadness + sigmoidnode5[5] * anger + sigmoidnode5[6] * surprise + sigmoidnode5[7] * contempt + sigmoidnode5[8] * calm + sigmoidnode5[9] * angered + sigmoidnode5[10] * joyful + sigmoidnode5[11] * sorrow;
	 firstcom[4] = sigmoidnode6[0] + sigmoidnode6[1] * joy + sigmoidnode6[2] * fear + sigmoidnode6[3] * disgust + sigmoidnode6[4] * sadness + sigmoidnode6[5] * anger + sigmoidnode6[6] * surprise + sigmoidnode6[7] * contempt + sigmoidnode6[8] * calm + sigmoidnode6[9] * angered + sigmoidnode6[10] * joyful + sigmoidnode6[11] * sorrow;
	 firstcom[5] = sigmoidnode7[0] + sigmoidnode7[1] * joy + sigmoidnode7[2] * fear + sigmoidnode7[3] * disgust + sigmoidnode7[4] * sadness + sigmoidnode7[5] * anger + sigmoidnode7[6] * surprise + sigmoidnode7[7] * contempt + sigmoidnode7[8] * calm + sigmoidnode7[9] * angered + sigmoidnode7[10] * joyful + sigmoidnode7[11] * sorrow;
	 double secondcomp[6];
	 for (int i = 0; i < 6; i++)
	 {
		 //secondcomp[i]= ((1 - (exp(-(2 * firstcom[i])))) / (1 + (exp(-(2 * firstcom[i])))));
		 //secondcomp[i] = (1 / (1+(exp(-firstcom[i]))));
		 secondcomp[i] = tanh(firstcom[i]);
	 }
	 double successcalc1 = sigmoidnode0[0] + sigmoidnode0[1] * secondcomp[0] + sigmoidnode0[2] * secondcomp[1] + sigmoidnode0[3] * secondcomp[2] + sigmoidnode0[4] * secondcomp[3] + sigmoidnode0[5] * secondcomp[4] + sigmoidnode0[6] * secondcomp[5];
	 //double successcalc2 = ((1 - (exp(-(2 * successcalc1)))) / (1 + (exp(-(2 * successcalc1)))));
	 //double successcalc2 = (1 / (1 + (exp(-successcalc1))));
	 double successcalc2 = tanh(successcalc1);
	 double failcalc1 = sigmoidnode1[0] + sigmoidnode1[1] * secondcomp[0] + sigmoidnode1[2] * secondcomp[1] + sigmoidnode1[3] * secondcomp[2] + sigmoidnode1[4] * secondcomp[3] + sigmoidnode1[5] * secondcomp[4] + sigmoidnode1[6] * secondcomp[5];
	 //double failcalc2 = ((1 - (exp(-(2 * failcalc1)))) / (1 + (exp(-(2 * failcalc1)))));
	 //double failcalc2 = (1 / (1 + (exp(-failcalc1))));
	 double failcalc2 = tanh(failcalc1);
	 cout << "SUCCESS: " << successcalc2 << "  FAIL " << failcalc2 << endl;
	 nsucsum = successcalc2 + nsucsum;
	 nfaisum = failcalc2 + nfaisum;
	 if (successcalc2 > failcalc2)
	 {
		 d.insertNNResult(samplenum, i, successcalc2, failcalc2, "SUCCESS");
	 }
	 else
	 {
		 d.insertNNResult(samplenum, i, successcalc2, failcalc2, "FAIL");
	 }
 }
 void AffectivaProcess(string AffPath, string TimPath)
 {
	 cout << "Runs Affectiva" << endl;
	//insert Affectiva ShellExecute Here, and edit affpath for the csv. 
	 line l;
	 string in;
	 int i = 0;
	 int k = 0;
	 string inputs[53];
	 ifstream input(AffPath);
	 if (!input.is_open())
		 cout << "Error: File Open" << '\n';
	 try {
		 while (input.good())
		 {


			 for (int i = 0; i<52; i++)
			 {
				 getline(input, inputs[i], ',');
			 }
			 getline(input, inputs[52], '\n');
			 l.setvalues(inputs[0], inputs[1], inputs[2], inputs[3], inputs[4], inputs[5], inputs[6], inputs[7], inputs[8], inputs[9], inputs[10], inputs[11], inputs[12], inputs[13], inputs[14], inputs[15], inputs[16], inputs[17], inputs[18], inputs[19], inputs[20], inputs[21], inputs[22], inputs[23], inputs[24], inputs[25], inputs[26], inputs[27], inputs[28], inputs[29], inputs[30], inputs[31], inputs[32], inputs[33], inputs[34], inputs[35], inputs[36], inputs[37], inputs[38], inputs[39], inputs[40], inputs[41], inputs[42], inputs[43], inputs[44], inputs[45], inputs[46], inputs[47], inputs[48], inputs[49], inputs[50], inputs[51], inputs[52]);
			 vic.push_back(l);
			 i++;
		 }
	 }
	 catch (exception e)
	 {
		 input.close();
	 }
	 input.close();
	 ifstream times(TimPath);
	 if (!times.is_open())
		 cout << "Error: File Open" << '\n';
	 try {
		 while (times.good())
		 {
			 getline(times, in, '\n');
			 cout << in << endl;
			 timestamps[k] = stod(in);
			 in = "";
			 k++;
		 }
	 }
	 catch (exception e)
	 {
		 times.close();
	 }
	 times.close();
	 cout << "Maximum emotions per Questions" << endl;
	 for_each(vic.begin(), vic.end(), split);
	 for_each(vic1.begin(), vic1.end(), reveal);
	 displaymax(1);
	 for_each(vic2.begin(), vic2.end(), reveal);
	 displaymax(2);
	 for_each(vic3.begin(), vic3.end(), reveal);
	 displaymax(3);
	 for_each(vic4.begin(), vic4.end(), reveal);
	 displaymax(4);
	 for_each(vic5.begin(), vic5.end(), reveal);
	 displaymax(5);
	 for_each(vic6.begin(), vic6.end(), reveal);
	 displaymax(6);
	 for_each(vic7.begin(), vic7.end(), reveal);
	 displaymax(7);
	 for_each(vic8.begin(), vic8.end(), reveal);
	 displaymax(8);
	 for_each(vic9.begin(), vic9.end(), reveal);
	 displaymax(9);
	 for_each(vic10.begin(), vic10.end(), reveal);
	 displaymax(10);
	 for_each(vic11.begin(), vic11.end(), reveal);
	 displaymax(11);
	 for_each(vic12.begin(), vic12.end(), reveal);
	 displaymax(12);
	 for_each(vic13.begin(), vic13.end(), reveal);
	 displaymax(13);
	 for_each(vic14.begin(), vic14.end(), reveal);
	 displaymax(14);
	 for_each(vic15.begin(), vic15.end(), reveal);
	 displaymax(15);
	 for_each(vic16.begin(), vic16.end(), reveal);
	 displaymax(16);
	 for_each(vic17.begin(), vic17.end(), reveal);
	 displaymax(17);
	 for_each(vic18.begin(), vic18.end(), reveal);
	 displaymax(18);
	 for_each(vic19.begin(), vic19.end(), reveal);
	 displaymax(19);
	 for_each(vic20.begin(), vic20.end(), reveal);
	 displaymax(20);
	 for_each(vic21.begin(), vic21.end(), reveal);
	 displaymax(21);
	 for_each(vic22.begin(), vic22.end(), reveal);
	 displaymax(22);
	 for_each(vic23.begin(), vic23.end(), reveal);
	 displaymax(23);
	 for_each(vic24.begin(), vic24.end(), reveal);
	 displaymax(24);
	 for_each(vic25.begin(), vic25.end(), reveal);
	 displaymax(25);
	 for_each(vic26.begin(), vic26.end(), reveal);
	 displaymax(26);
	 for_each(vic27.begin(), vic27.end(), reveal);
	 displaymax(27);
	 for_each(vic28.begin(), vic28.end(), reveal);
	 displaymax(28);
	 for_each(vic29.begin(), vic29.end(), reveal);
	 displaymax(29);
	 for_each(vic30.begin(), vic30.end(), reveal);
	 displaymax(30);
	 for_each(vic31.begin(), vic31.end(), reveal);
	 displaymax(31);
	 for_each(vic32.begin(), vic32.end(), reveal);
	 displaymax(32);
	 for_each(vic33.begin(), vic33.end(), reveal);
	 displaymax(33);
	 for_each(vic34.begin(), vic34.end(), reveal);
	 displaymax(34);
	 cout << "1. ";
	 for (int i = 0; i < 7; i++)
	 {
		 cout << maxvalues[0][i]<<endl;
	 }
		 
	 
 }
 void EmpathProcess(string EmpPath, string TemPath)
 {
	 string parameter = "-jar C:\\Users\\Lenovo\\Desktop\\Thesis\\EMPATHCMS\\EmpathCMS2.jar 9_KjnGMlmjVaJLMphp4dJi4ZQoDKLoWWs-q9bsFPpB8 "+EmpPath+" "+TemPath;
	 LPCSTR parameters = parameter.c_str();
	 string extract;
	 cout << "Runs Empath";
	 ShellExecuteA(NULL, "open", "C:\\Program Files (x86)\\Common Files\\Oracle\\Java\\javapath\\java.exe",parameters, NULL, SW_SHOWMAXIMIZED);
	 system("PAUSE");
	 ifstream tempfile;
	 int n = 0;

	 tempfile.open(TemPath);
	 while (tempfile.good())
	 {
		 getline(tempfile, extract, '}');
		 empathstring(extract, n);
		 n++;
	 }
	 tempfile.close();
	 combine();
	 for (int i = 0; i < 34; i++)
	 {
		 int h = i + 1;
		 cout << "No." << h;
		 for (int j = 0; j < 11; j++)
		 {
			 cout << " " << combinedvalues[i][j];
		 }
		 cout << endl;
	 }
	 system("PAUSE");
	 system("CLS");
 }
 void DatabaseInsert()
 {
	 for (int i = 0; i < 34; i++)
	 {
		 int j = i + 1;
		 Combined c(samplenum,j,combinedvalues[i][0],combinedvalues[i][1], combinedvalues[i][2], combinedvalues[i][3], combinedvalues[i][4], combinedvalues[i][5], combinedvalues[i][6], combinedvalues[i][7], combinedvalues[i][8], combinedvalues[i][9], combinedvalues[i][10] );
		 d.insertData(c);
	 }
	
	 
 }
 int main()
{
	 
	 cout << "Please Enter Sample Number" << endl;
	 cin >> samplenum;
	cout << "Please Enter Video Path" << endl;
	string afpath = "C:\\Users\\Lenovo\\Desktop\\Thesis\\Interview\\CSV Files\\20171016080633.csv";
	cout << "Please Enter Timestamp" << endl;
	string tipath = "C:\\Users\\Lenovo\\Desktop\\Thesis\\CSVMaximum\\CSVMaximum\\Timestamps.txt";
	AffectivaProcess(afpath, tipath);//Affectiva Code is placed here. You can add the Affectiva Video for ShellExecute in Here
	cout << "Please Enter Audio Path" << endl;
	string Empath = "C:\\Users\\Lenovo\\Desktop\\Thesis\\Interview\\SegmentedCuts\\Number59\\59";
	cout << "Please Enter Temp Path" << endl;
	string Tepath = "C:\\Users\\Lenovo\\Desktop\\Thesis\\EMPATHCMS\\Temporary.txt";
	EmpathProcess(Empath, Tepath);
	system("PAUSE");
	DatabaseInsert();
	system("CLS");
	system("PAUSE");
	int NBSuccess = 0;
	int NBFail = 0;
	string NBfinaldecision;
	int J48Success = 0;
	int J48fail = 0;
	string J48finaldecision;
	int SVMSuccess = 0;
	int SVMfail = 0;
	string SVMfinaldecision;
	int g = 1;
	string dec;
	string dec1;
	string dec2;
	for (int i = 1; i < 35; i++)
	{
		
		dec = SVMdecision(i,combinedvalues[i][0],combinedvalues[i][1], combinedvalues[i][2], combinedvalues[i][3], combinedvalues[i][4], combinedvalues[i][5], combinedvalues[i][6], combinedvalues[i][7], combinedvalues[i][8], combinedvalues[i][9], combinedvalues[i][10]);
		dec1 = J48decision(i,combinedvalues[i][0], combinedvalues[i][1], combinedvalues[i][2], combinedvalues[i][3], combinedvalues[i][4], combinedvalues[i][5], combinedvalues[i][6], combinedvalues[i][7], combinedvalues[i][8], combinedvalues[i][9], combinedvalues[i][10]);
		dec2 = NBdecision(i,combinedvalues[i][0], combinedvalues[i][1], combinedvalues[i][2], combinedvalues[i][3], combinedvalues[i][4], combinedvalues[i][5], combinedvalues[i][6], combinedvalues[i][7], combinedvalues[i][8], combinedvalues[i][9], combinedvalues[i][10]);
		cout << g << ". NB: " << dec2 << " SVM: " << dec << " Value: " << sout << " J48: " << dec1 << " Neural: ";
		NNdecision(i,combinedvalues[i][0], combinedvalues[i][1], combinedvalues[i][2], combinedvalues[i][3], combinedvalues[i][4], combinedvalues[i][5], combinedvalues[i][6], combinedvalues[i][7], combinedvalues[i][8], combinedvalues[i][9], combinedvalues[i][10]);
		if (dec2 == "Success")
			NBSuccess++;
		else
			NBFail++;
		if (dec == "SUCCESS")
			SVMSuccess++;
		else
			SVMfail++;
		if (dec1 == "SUCCESS")
			J48Success++;
		else
			J48fail++;
		g++;
	}
	if (NBSuccess > NBFail)
		NBfinaldecision = "SUCCESS";
	else
		NBfinaldecision = "FAIL";
	if (SVMSuccess > SVMfail)
		SVMfinaldecision = "SUCCESS";
	else
		SVMfinaldecision = "FAIL";
	if (J48Success > J48fail)
		J48finaldecision = "SUCCESS";
	else
		J48finaldecision = "FAIL";
	double nsucmean = nsucsum / 34;
	double nfaimean = nfaisum / 34;
	string NNfinaldecision;
	if (nsucmean > nfaimean)
		NNfinaldecision = "SUCCESS";
	else
		NNfinaldecision = "FAIL";
	cout << "Final Decision: NB: " << NBfinaldecision << " SVM: " << SVMfinaldecision << " J48: " << J48finaldecision << " NN: " << NNfinaldecision;
	d.databaseclose();
	system("PAUSE");
	return 0;
}


