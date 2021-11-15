//decay.cpp

#include "TMath.h"
#include "TLorentzVector.h"
#include "TRandom.h"
#include "TH1F.h"
#include "TCanvas.h"
#include<iostream>
#include<vector>
#include<typeinfo>
using namespace std;

int main(){
  //Creo 4-momento per B nel lab
  TLorentzVector p4_B,p4_pi,p4_K;
  double p_pi_0, p_pi_meas, p_K_0, p_K_meas;
  double m_B=5.279; //Gev
  double p_B=0.3; //Gev
  double m_K=0.500; //GeV
  double m_pi=0.140; //GeV
  int samples=1e4;
  double invariant_mass;
  int n_bins=100;
  double sigma[]={0.01,0.03,0.05,0.1};
  TH1F hist_s("hist_s","Invariant mass of daugthers in LAB frame",n_bins,0,10);
  TH1F hist_angles("hist_angles","Opening angles between daugthers in LAB frame",1000,2,4);
  TH1F hist_smear_3("hist_smear_3","Measured invariant mass in LAB frame",n_bins,0,10);
  TH1F hist_smear_1("hist_smear_1","Measured invariant mass in LAB frame",n_bins,0,10);
  TH1F hist_smear_5("hist_smear_5","Measured invariant mass in LAB frame",n_bins,0,10);
  TH1F hist_smear_10("hist_smear_10","Measured invariant mass in LAB frame",n_bins,0,10);  
  vector<TH1F> hist={hist_smear_1,hist_smear_3,hist_smear_5,hist_smear_10};
  int count=0;
  TCanvas c1("c1","Canvas",1024,800);
  p4_B.SetPxPyPzE(p_B,0,0,sqrt(p_B*p_B+m_B*m_B));

  //generazione casuale 3 momento
  TRandom* rand=new TRandom;
  rand->SetSeed(time(NULL)); //seed
  double p_star=sqrt(m_B*m_B*m_B*m_B+m_pi*m_pi*m_pi*m_pi+m_K*m_K*m_K*m_K-2*m_B*m_B*m_pi*m_pi-2*m_B*m_B*m_K*m_K-2*m_pi*m_pi*m_K*m_K)/(2*m_B);
  double tmp_x,tmp_y,tmp_z,tmp_pi,tmp_K;
  for(int i=0;i<samples;i++){
    rand->TRandom::Sphere(tmp_x,tmp_y,tmp_z,p_star);
    //creo 4-momento nel cdm
    p4_pi.SetPxPyPzE(tmp_x,tmp_y,tmp_z,sqrt(m_pi*m_pi+p_star*p_star));
    p4_K.SetPxPyPzE(-tmp_x,-tmp_y,-tmp_z,sqrt(m_K*m_K+p_star*p_star));
    //li boosto nel lab
    p4_pi.Boost(p4_B.BoostVector());
    p4_K.Boost(p4_B.BoostVector());
    //calcolo massa invariante e fillo istogramma
    invariant_mass=(p4_pi+p4_K).M();
    hist_s.Fill(invariant_mass);
    hist_angles.Fill(p4_pi.Angle(p4_K.Vect()));
    //simulo un detector gaussiano che misura nel lab gli impulsi di pi e K
    p_pi_0=(p4_pi.Vect()).Mag();
    p_K_0=(p4_K.Vect()).Mag();
    for(double sig:sigma){
      p_pi_meas=rand->TRandom::Gaus(p_pi_0,sig*p_pi_0);
      tmp_x=p_pi_meas*cos(p4_pi.Theta())*sin(p4_pi.Phi());
      tmp_y=p_pi_meas*sin(p4_pi.Theta())*sin(p4_pi.Phi());
      tmp_z=p_pi_meas*sin(p4_pi.Phi());
      
      p4_pi.SetPxPyPzE(tmp_x,tmp_y,tmp_z,sqrt(p_pi_meas*p_pi_meas+m_pi*m_pi));
      
      p_K_meas=rand->TRandom::Gaus(p_K_0,sig*p_K_0);
      tmp_x=p_K_meas*cos(p4_K.Theta())*sin(p4_K.Phi());
      tmp_y=p_K_meas*sin(p4_K.Theta())*sin(p4_K.Phi());
      tmp_z=p_K_meas*sin(p4_K.Phi());
      
      p4_K.SetPxPyPzE(tmp_x,tmp_y,tmp_z,sqrt(p_K_meas*p_K_meas+m_K*m_K));
    
      //calcolo massa invariante e fillo istogramma
      invariant_mass=(p4_pi+p4_K).M();
      //hist_smear3.Fill(invariant_mass);
      (hist[count]).Fill(invariant_mass);
      count++;
    }
  }
  for(int i=0;i<4;i++){
    hist_s.GetXaxis()->SetTitle("Invariant Mass [GeV]");
    hist_s.Draw();
    hist[i].Draw("same");
    c1.SaveAs("invariant-mass.pdf");
  }
  
  hist_s.GetXaxis()->SetTitle("Invariant Mass [GeV]");
  hist_s.Draw();
  c1.SaveAs("true-mass.pdf");
  
  hist_angles.GetXaxis()-> SetTitle("Theta [rad]");
  hist_angles.Draw();
  c1.SaveAs("opening-angle.pdf");  
  
  hist_smear_3.GetXaxis()->SetTitle("Measured Invariant Mass [GeV]");
  hist_smear_3.Draw();
  c1.SaveAs("measured-mass.pdf");
  
  delete rand;
}
