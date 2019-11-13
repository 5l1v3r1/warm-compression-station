function v = iFH()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 68);
  end
  v = vInitialized;
end
