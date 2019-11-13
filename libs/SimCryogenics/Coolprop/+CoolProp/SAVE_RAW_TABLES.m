function v = SAVE_RAW_TABLES()
  persistent vInitialized;
  if isempty(vInitialized)
    vInitialized = CoolPropMATLAB_wrap(0, 133);
  end
  v = vInitialized;
end
