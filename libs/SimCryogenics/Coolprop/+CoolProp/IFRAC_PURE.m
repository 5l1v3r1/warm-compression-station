function v = IFRAC_PURE()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 87);
  end
  v = vInitialized;
end
