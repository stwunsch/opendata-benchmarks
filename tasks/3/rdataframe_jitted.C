void rdataframe_jitted() {
    ROOT::EnableImplicitMT();
    ROOT::RDataFrame df("Events", "root://eospublic.cern.ch//eos/root-eos/benchmark/Run2012B_SingleMu.root");
    auto h = df.Define("goodJet_pt", "Jet_pt[abs(Jet_eta) < 1.0]")
               .Histo1D({"", ";Jet p_{T} (GeV);N_{Events}", 100, 15, 60}, "goodJet_pt");

    TCanvas c;
    h->Draw();
    c.SaveAs("3_rdataframe_jitted.png");
}
